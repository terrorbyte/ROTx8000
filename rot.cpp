#include <iostream>
#include <locale>
#include <bitset>

std::wstring rot_utf8(std::wstring str, int bit){
  std::wstring tmp;
  for(std::wstring::iterator it = str.begin(); it != str.end(); ++it) {
    std::bitset<16> x(*it);
    tmp += x.flip(bit).to_ulong();
  }
  return tmp;
}

int main(){
  if (!setlocale(LC_CTYPE, "")){
    std::cerr << "Locale not specified. Check LANG, LC_CTYPE, LC_ALL.";
    return 1;
  }
    std::wstring str;
    std::getline(std::wcin,str);
    std::wcout << rot_utf8(str,15) << "\n";
}
