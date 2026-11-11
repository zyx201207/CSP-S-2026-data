#include<bits/stdc++.h>
using namespace std;
int main(){
   bool a=0,b=0,c=0,d=0;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1,c1,d1;
    cin>>a1>>b1>>c1>>d1;
    if(a1==c1){
        a=1;
    }
    if(a==1&&b1[0]==d1[0]&&b1[1]==d1[1]){
        b=1;
    }
    if(b==1&&(b1[2]>='A'&&b1[2]<='C'&&d1[2]>='A'&&d1[2]<='C')||(b1[2]>='D'&&b1[2]<='F'&&d1[2]>='D'&&d1[2]<='F')){
        c=1;
    }
    int ab=b1[1]-'0';
    char ch=b1[2];
    int ab1=d1[1]-'0';
    char ch1=d1[2];
    if(a&&((ab==ab1||ch==ch1)&&abs(ab-ab1)<=1&&abs(ch-ch1)<=1)&&(b1[2]>='A'&&b1[2]<='C'&&d1[2]>='A'&&d1[2]<='C')||(b1[2]>='D'&&b1[2]<='F'&&d1[2]>='D'&&d1[2]<='F')){
        d=1;
    }
    cout<<a<<b<<c<<d<<endl;
    return 0;
}
