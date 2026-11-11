#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r","stdin");
    freopen("travel.out"."w","stdout");
for(int i = 0;i < 4;i++){
    string c1,c2;
    string s1,s2;
    cin>>c2>>s1>>c2>>s2;
    if(c1 == c2){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&s1[0] == s2[0]&&s1[1]==s2[1]){
        cout<<1;
    }else{
        cout<<0;
    }
    if(c1==c2&&s1[0] == s2[0]&&s1[1]==s2[1]&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))){
        cout<<1;
    }else{
        cout<<0;
    int a = s1[2]-'A';
    int b = s2[2]-'A';
    if(c1==c2&&s1[0] == s2[0]&&s1[1]==s2[1]&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))&&(a-b==1||a-b==-1)){
        cout<<1;
    }else{
        cout<<0;
    }

}
return 0;
}
