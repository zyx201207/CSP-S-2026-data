#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int c1,c2;
string s1,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        int p1=0,p2=0;
        for(int i=0;i<2;++i){
            p1*=10;
            p2*=10;
            p1+=s1[i]-'0';
            p2+=s2[i]-'0';
        }
        if(p1==p2){
            cout<<"1";
            int st1=s1[2]-'A',st2=s2[2]-'A';
            if(min(st1,st2)>=3||max(st1,st2)<=2){
                cout<<"1";
                if(abs(st1-st2)==1){
                    cout<<"1"<<endl;
                }else{
                    cout<<"0"<<endl;
                }
            }else{
                cout<<"00"<<endl;
            }
        }else{
            cout<<"000"<<endl;
        }
    }else{
        cout<<"0000"<<endl;
    }
    return 0;
}