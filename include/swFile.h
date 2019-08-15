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
   * @brief Writes given data but erase previous if file exist already
   * @param data
   * @param size of data
   *
   * NOTE: File needs to be created before write() otherwise it does nothing
   */
  void
  overWrite(const Vector<unsigned char>& data);

  /**
 * @brief Writes given data in created file
 * @param data
 * @param size of data
 *
 * NOTE: File needs to be created before write() otherwise it does nothing
 */
  void
  write(const Vector<unsigned char>& data);

  /** 
   * @brief read this file 
   * @param[out] data extracted from this file will be save here
   * @param[out] size of info extracted
   */
  void
  read(Vector<unsigned char>& data);

 private:

   /** 
    * @brief name of this file
    */
   String m_name = "Prueba";
 
};
}

