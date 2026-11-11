#include<bits/stdc++.h>
using namespace std;
int a1,a2,a3,b1,b2,b3;
string s1,s2,t1,t2;
bool check(int x){
    return x>=1&&x<=3;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>t1>>t2;
    for(int i=0;i<2;i++) a1=a1*10+(s1[i]-'0');
    for(int i=0;i<2;i++) a2=a2*10+(s2[i]-'0');
    for(int i=0;i<2;i++) b1=b1*10+(t1[i]-'0');
    for(int i=0;i<2;i++) b2=b2*10+(t2[i]-'0');
    a3=s2[2]-'A'+1; b3=t2[2]-'A'+1;
    if(a3==6) a3--;
    if(b3==6) b3--;
    if(a1==b1) cout<<'1';
    else{
        cout<<"0000";
        return 0;
    }
    if(a2==b2) cout<<'1';
    else{
        cout<<"000";
        return 0;
    }
    if((check(a3)&&check(b3))||!(check(a3)||check(b3))) cout<<'1';
    else{
        cout<<"00";
        return 0;
    }
    if(abs(a3-b3)==1) cout<<'1';
    else cout<<'0';
//    cout<<'\n'<<a1<<' '<<a2<<' '<<a3<<'\n'<<b1<<' '<<b2<<' '<<b3;
    return 0;
}
