#include "tgl.h"
#include <corecrt_malloc.h>

struct glCommandBufferData
{
	uint8_t* pData = nullptr;
	size_t bufferSize = 0;
	size_t bufferBase = 0;
};

glCommandBuffer glAllocateCommandBuffer()
{
	return new glCommandBuffer_t{ new uint8_t[ 128 ], 128, 0 };
}

void glSubmitCommandBuffer( glCommandBuffer cmdBuffer )
{
	size_t pointer = 0;
	while ( pointer < cmdBuffer->base )
	{
		glCommand* cmdbase = (glCommand*)(cmdBuffer->pData + pointer);
		
		switch ( cmdbase->cmdType )
		{
		case glCmdType_BindBuffer:
		{
			glBindBufferCommand* cmd = ( glBindBufferCommand* )cmdbase;
			pointer += sizeof( glBindBufferCommand );
			glBindBuffer( cmd->target, cmd->buffer );
		}
		}
	}
}

void glPushCommandData( glCommandBuffer cmdBuffer, void* data, size_t size )
{
	if ( cmdBuffer->base + size > cmdBuffer->size )
		cmdBuffer->pData = (uint8_t*)realloc( cmdBuffer->pData, cmdBuffer->size + 128 );
	
	memcpy( cmdBuffer->pData + cmdBuffer->base, data, size );
	cmdBuffer->base += size;
}
