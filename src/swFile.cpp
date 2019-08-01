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

  //Open file with name given, binary write and just for write
  fout.open(m_name, std::ios::binary | std::ios::in);

  //If couldn't open it then return doing nothing
  if(fout.fail())
  {
    return;
  }

  fout.write(static_cast<char*>(data), size);
  fout.close();
}

/*
*/
void
File::read(void* data)
{
  std::ifstream fout;
  //Open file with name given, binary write and just for read
  fout.open(m_name, std::ios::binary | std::ios::out);

  //If couldn't open it then return doing nothing
  if(fout.fail())
  {
    return;
  }
  
  Vector<unsigned char> buffer(std::istreambuf_iterator<char>(fout), {});

  return;


}

}