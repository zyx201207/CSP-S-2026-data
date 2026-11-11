#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+7;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2;
    cout<<(c1==c2);
    if(c1!=c2){
        cout<<"000";return 0;
    }
    string t1,t2;
    t1=s1[0]+s1[1];
    t2=s2[0]+s2[1];
    cout<<(c1==c2&&t1==t2);
    if((c1==c2&&t1==t2)==0){
        cout<<"00";return 0;
    }
    char ch1,ch2;
    ch1=s1[2];ch2=s2[2];
    if(ch1!='D'&&ch1!='F'&&ch2!='D'&&ch2!='F'){
        cout<<1<<(abs(ch1-ch2)==1);
    }else if((ch1=='D'&&ch2=='F')||(ch1=='F'&&ch2=='D')){
        cout<<1<<1;
    }else{
        cout<<0<<0;
    }
    cout<<endl;
    return 0;
}