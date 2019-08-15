/************************************************************************/
/**
 * @file swTextureInfo.h
 * @author AccelMR
 * @date 2019/08/01
 * @brief Texture pixel information
 */
 /************************************************************************/

/************************************************************************/
/*
 * Includes
 */                                                                     
/************************************************************************/
#include "swTextureInfo.h"

#define STB_IMAGE_IMPLEMENTATION
#include "Externals/stb_image.h"

#include <iostream>

/* =^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=   =^..^=  */
/* =^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=   =^..^=  */
namespace swEngineSDK{

/*
*/

TextureInfo::TextureInfo()
  : m_width(0),
    m_height(0), 
    m_channels (4) {}

/*
*/

TextureInfo::~TextureInfo()
{

}

/*
*/
void
TextureInfo::loadTextureInfo(const String& filePath)
{
  //Read Texture information
  auto* info = stbi_load(filePath.c_str(), &m_width, &m_height, &m_channels, 4);

  //If texture can't be read, then return
  if (nullptr == info)
  {
    std::cout << "Error loading textures " << std::endl;
  }

  //Copy to internal variables
  int32 size = m_width * m_height;
  m_textureInfo.resize(size);
  memcpy(&m_textureInfo[0], &info[0], size);
}

}
