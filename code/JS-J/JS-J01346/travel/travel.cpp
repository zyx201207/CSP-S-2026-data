#include<bits/stdc++.h>
using namespace std;
#define int long long

string c1,c2,s1,s2;
int a1,a2,b1,b2;
char a,b;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=c1.size()-1;i++){
        if(c1[i]>='1' and c1[i]<='9'){
            a1=a1*10+c1[i]-'0';
        }
        if(c2[i]>='1' and c2[i]<='9'){
            a2=a2*10+c2[i]-'0';
        }
    }
    if(a1==a2){
        cout<<1;
    }else{
        cout<<"0000"<<endl;
        return 0;
    }
    for(int i=0;i<=s1.size()-1;i++){
        if(s1[i]>='A' and s1[i]<='F'){
            if(s1[i]=='F'){
                a=='E';
            }else{
                a=s1[i];
            }
        }
        if(s2[i]>='A' and s2[i]<='F'){
            if(s2[i]=='F'){
                b=='E';
            }else{
                b=s2[i];
            }
        }
        if(s1[i]>='1' and s1[i]<='9'){
            b1=b1*10+s1[i]-'0';
        }
        if(s2[i]>='1' and s2[i]<='9'){
            b2=b2*10+s2[i]-'0';
        }
    }
    if(b1==b2){
        cout<<1;
        if(a<='C' and b<='C'){
            cout<<1;
        }else if(a>='D' and b>='D'){
            cout<<1;
        }else{
            cout<<"00"<<endl;
            return 0;
        }
        if(abs(a-b)==1){
            cout<<1<<endl;
        }else{
            cout<<0;
            return 0;
        }
    }else{
        cout<<"000"<<endl;
        return 0;
    }
    return 0;
}
