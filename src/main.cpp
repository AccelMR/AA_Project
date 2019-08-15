#include "swPrerequisitesProject.h"
#include "swFile.h"
#include "swTextureInfo.h"

int main()
{
  //Helper variables
  swEngineSDK::File myFile;
  swEngineSDK::TextureInfo myTexture;
  swEngineSDK::TextureInfo textureCpy;

  //Load texture pixels
  myTexture.loadTextureInfo(R"(Resources\Red.bmp)");

  //Creates an empty File
  myFile.create("Prueba");
  
  //Writes the Texture info to empty file
  myFile.overWrite(myTexture.getInfo());

  //Create temporal variables 
  swEngineSDK::Vector<unsigned char> info;
  swEngineSDK::int32 size;

  //Extract info from previous texture and writes it in temporal variables
  myFile.read(info);

  //Set the new info to texture copy
  textureCpy.setInfo(info);
  
  return 0;
}
