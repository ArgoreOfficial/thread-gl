#pragma once

#include <cstdint>
#include <glad/glad.h>

#define TGL_DEFINE_OPAQUE_HANDLE( _c ) typedef struct _c##_t* _c
#define TGL_DEFINE_HANDLE( _c ) typedef uint64_t _c

// TGL_DEFINE_OPAQUE_HANDLE( glCommandBuffer );

typedef struct glCommandBuffer_t
{
	uint8_t* pData = nullptr;
	size_t size = 0;
	size_t base = 0;
}* glCommandBuffer;

enum glCmdType
{
	glCmdType_BindBuffer
};

struct glCommand
{
	glCmdType cmdType;
};

glCommandBuffer glAllocateCommandBuffer();
void glSubmitCommandBuffer( glCommandBuffer cmdBuffer );

void glPushCommandData( glCommandBuffer cmdBuffer, void* data, size_t size );

/* Begin Generated */

typedef struct glBindBufferCommand : public glCommand { GLenum target; GLuint buffer; };
static void glCmdBindBuffer( glCommandBuffer cmdBuffer, GLenum target, GLuint buffer ) 
{ 
	glBindBufferCommand cmd{ glCmdType_BindBuffer, target, buffer }; 
	glPushCommandData( cmdBuffer, &cmd, sizeof( cmd ) );
}

/* End Generated */