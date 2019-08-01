/************************************************************************/
/**
 * @file swFile.h
 * @author AccelMR
 * @date 2019/08/01
 * @brief Class to create files, it'll be just in bytes
 */
 /************************************************************************/

/************************************************************************/
/*
 * Includes
 */
 /************************************************************************/
#include "swFile.h"

#include <iostream>

/* =^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=   =^..^=  */
/* =^..^=   =^..^=   =^..^=    =^..^=    =^..^=    =^..^=    =^..^=   =^..^=  */
namespace swEngineSDK{

/*
*/
File::File() {}

/*
*/
File::~File() {}

/*
*/
void
File::create(String name)
{
  m_name = name;

  std::ofstream file;
  file.open(m_name.c_str());
  file.close();
}

/*
*/
void
File::write(void* data, int size)
{
  std::ofstream fout;
  fout.open(m_name, std::ios::binary | std::ios::out);

  if(fout.is_open())
  {
    fout.write(static_cast<char*>(data), size);
    fout.close();
  }
}

}