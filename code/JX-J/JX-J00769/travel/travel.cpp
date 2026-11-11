#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define int long long

string c1,s1,c2,s2;
char ans[6];
bool pd1(){
    if(c1==c2)return true;
    else return false;
}
bool pd2(){
    if(s1[0]==s2[0]&&s1[1]==s2[1])return true;
    else return false;
}
bool pd3(){
    if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'))return true;
    else return false;
}
bool pd4(){
    if((s1[2]==char(s2[2]+1))||(s2[2]==char(s1[2]+1))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))return true;
    else return false;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(pd1()==true)ans[1]='1';
    else ans[1]='0';
    if(ans[1]=='1'&&pd2()==true)ans[2]='1';
    else ans[2]='0';
    if(ans[1]=='1'&&ans[2]=='1'&&pd3()==true)ans[3]='1';
    else ans[3]='0';
    if(ans[1]=='1'&&ans[2]=='1'&&ans[3]=='1'&&pd4()==true)ans[4]='1';
    else ans[4]='0';
    for(int i=1;i<=4;i++)
        cout<<ans[i];
    return 0;
}
