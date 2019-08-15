/************************************************************************/
/**
 * @file swTextureInfo.h
 * @author AccelMR
 * @date 2019/08/01
 * @brief Texture pixel information
 */
 /************************************************************************/
#pragma once

/************************************************************************/
/*
 * Includes
 */                                                                     
/************************************************************************/
#include "swPrerequisitesProject.h"

/* =^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=   =^..^=  */
/* =^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=   =^..^=  */
namespace swEngineSDK{
class TextureInfo
{
 public:
 /*
  * @brief Default constructor
  */
  TextureInfo();

 /*
  * @brief Default destructor
  */
  ~TextureInfo();

  /** 
   * @brief Loads Texture info
   * @param file path
   */
  void
  loadTextureInfo(const String& filePath);

  /** 
   * @brief Gets the information
   * return Vector of information
   */
  Vector<unsigned char>
  getInfo() const {
    return m_textureInfo;
  }
    
  /** 
   * @brief Get size of information
   */
  uint32
  getSize() {
    return m_width * m_height;
  }

  /** 
   * @brief Sets a new information
   */
  void 
  setInfo(Vector<unsigned char>& info) {
    m_textureInfo.resize(info.size());
    memcpy(&m_textureInfo[0], &info[0], info.size());
  }


 private:

   /** 
    * @brief Info in pixels of what the texture have
    */
   Vector<unsigned char> m_textureInfo;

   /** 
    * @brief Width and height of texture info
    */
   int32 m_width, m_height;

   /** 
    * @brief used channels of image
    * NOTE: we usually want to have 4
    */
   int32 m_channels;
 
};
}
