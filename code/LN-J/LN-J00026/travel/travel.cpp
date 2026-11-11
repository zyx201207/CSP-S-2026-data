#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s;
int k1=0,k2=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=1;i++){
        k1=k1*10+int(s1[i]-'0');
        k2=k2*10+int(s2[i]-'0');
    }
    int m1=int(s1[2]-'A'),m2=int(s2[2]-'A');
    if(c1!=c2){
        s+='0';
        s+='0';
        s+='0';
        s+='0';
        cout<<s;
        return 0;
    }else{
        s+='1';
        if(k1!=k2){
            s+='0';
            s+='0';
            s+='0';
            cout<<s;
            return 0;
        }else{
            s+='1';
            if(m1<=2&&m2<=2||m1>2&&m2>2){
                 s+='1';
                 if(abs(m1-m2)==1){
                     s+='1';
                     cout<<s;
                 }else{
                     s+='0';
                     cout<<s;
                 }
            }else{
                 s+='0';
                 s+='0';
                 cout<<s;
            }
        }
    }
    return 0;

}
