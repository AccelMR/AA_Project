/************************************************************************/
/**
 * @file swFile.h
 * @author AccelMR
 * @date 2019/08/01
 * @brief Class to create files, it'll be just in bytes
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
class File
{
 public:
 /*
  * @brief Default constructor
  */
  File();

 /*
  * @brief Default destructor
  */
  ~File();

  /** 
   * @brief creates a new file with given name
   */
  void
  create(String name);

  /** 
   * @brief Writes given data in created file
   * @param data
   * @param size of data
   *
   * NOTE: prefer create file before. 
   */
  void
  write(void* data, int size);

 private:

   /** 
    * @brief name of this file
    */
   String m_name;
 
};
}

