#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    int t1=c1==c2?1:0;
    int t2=t1&(s1[0]==s2[0]&&s1[1]==s2[1]);
    int t3=t2&(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C');
    int t4=t3&(abs(s1[2]-s2[2])==1&&s1[2]+s2[2]!=135);
    cout<<t1<<t2<<t3<<t4<<"\n";
    return 0;
}