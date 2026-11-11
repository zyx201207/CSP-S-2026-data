#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1,a2,b2;
    cin>>a1>>a2>>b1>>b2;
    string tt1="",tt2="";
    for(int i=0;i<=1;i++){
        tt1=tt1+a2[i];
        tt2=tt2+b2[i];
    }
    if(a1==b1) cout<<1;
    else       cout<<0;
    if(a1==b1&&tt1==tt2) cout<<1;
    else                 cout<<0;
    char ch1=a2[2],ch2=b2[2];
    int v1,v2;
    if(ch1=='A'||ch1=='B'||ch1=='C') v1=1;
    else                             v1=2;
    if(ch2=='A'||ch2=='B'||ch2=='C') v2=1;
    else                             v2=2;
    if(a1==b1&&tt1==tt2&&v1==v2) cout<<1;
    else                         cout<<0;
    if(a1==b1&&tt1==tt2&&v1==v2){
        if(v1==2) cout<<1;
        else{
            int tmp1=(int)ch1,tmp2=(int)ch2;
            if(abs(tmp1-tmp2)==1)  cout<<1;
            else                   cout<<0;
        }
    }
    else  cout<<0;
    return 0;
}
// 1 true 0 false
