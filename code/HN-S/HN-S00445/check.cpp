#include<bits/stdc++.h>
using namespace std;
int main(){
    int cnt=0;
    while(1){
        cout<<++cnt<<endl;
        system("gen.exe > a.txt");
        system("a1.exe < a.txt >out.txt");
        system("a2.exe < a.txt >out2.txt");

        if(system("diff out.txt out2.txt")){
            cout<<-1;
            return 0;
        }
    }
}
