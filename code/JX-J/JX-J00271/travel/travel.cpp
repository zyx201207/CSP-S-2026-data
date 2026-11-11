#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    int ans1,ans2;
    ans1=s1[0]-'0';
    ans1*=10;
    ans1+=s1[1]-'0';
    ans2=s2[0]-'0';
    ans2*=10;
    ans2+=s2[1]-'0';
    if(ans1!=ans2){
        cout<<"000";
        return 0;
    }
    cout<<1;
    int cmp1,cmp2;
    if(s1[2]>='A'&&s1[2]<='C') cmp1=0;
    else cmp1=1;
    if(s2[2]>='A'&&s2[2]<='C') cmp2=0;
    else cmp2=1;
    if(cmp1!=cmp2){
        cout<<"00";
        return 0;
    }
    cout<<1;
    int pd1,pd2;
    pd1=s1[2]-'A';
    pd2=s2[2]-'A';
    if((abs(pd1-pd2)==1&&pd1!=3&&pd2!=3)||(pd1==3&&pd2==5)||(pd1==5&&pd2==3)) cout<<1;
    else cout<<0;
    return 0;
}
