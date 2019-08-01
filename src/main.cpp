#include "swPrerequisitesProject.h"
#include "swFile.h"

int main()
{
  //swEngineSDK::String caca = "Popochas";
  int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
  int size = 0;

  int b[10];
  swEngineSDK::File myFile;

  myFile.create("Prueba");
  myFile.write(static_cast<void*>(&a[0]), sizeof(int) * 10);
  myFile.read(&b);
  
  return 0;
}
