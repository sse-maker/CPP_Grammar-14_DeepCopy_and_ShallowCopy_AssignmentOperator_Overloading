//
//  main.cpp
//  14_DeepCopy_and_ShallowCopy_AssignmentOperator_Overloading
//
//  Created by 세광 on 2021/07/02.
//

#include <iostream>

using namespace std;

class String {
public:
    String() {
        cout << "String() 생성자 호출" << endl;
        strData = NULL;
        len = 0;
    }
    
    String(const char *str) {
        cout << "String(const char*) 생성자 호출" << endl;
        len = strlen(str);
        strData = new char[len + 1];
        cout << "strData 할당: " << (void*)strData << endl;
        strcpy(strData, str);
    }
    
    // 복사 생성자
    String(const String &rhs) {
        cout << "String(String &rhs) 생성자 호츨" << endl;
        strData = new char[rhs.len + 1];
        cout << "strData 할당: " << (void*)strData << endl;
        strcpy(strData, rhs.strData);
        len = rhs.len;
    }
    
    ~String() {
        cout << "~String() 소멸자 호출" << endl;
        delete [] strData;
        cout << "strData 해제됨: " << (void*)strData << endl;
        strData = NULL;
    }
    
    // 복사 대입 연산자
    String &operator=(const String &rhs) { // &rhs: 래퍼런스
        if(this != &rhs) { // &rhs: 주소값
            delete [] strData;
            strData = new char[rhs.len + 1];
            cout << "strData 할당: " << (void*)strData << endl;
            strcpy(strData, rhs.strData);
            len = rhs.len;
        }
        return *this;
    }
    
    char *GetStrData() const {
        return strData;
    }
    
    int GetLen() const {
        return len;
    }
    
private:
    char *strData;
    int len;
};

int main() {
    String s1("안녕");
    String s2(s1); // 변수를 생성하는 동시에 복사가 일어남 -> 복사 생성자 호출
    String s3("Hello");
    s3.operator=(s1); // 복사 생성자를 호출할 수 없음 -> 연산자 오버로딩 사용
    
    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
    cout << s3.GetStrData() << endl;
}
