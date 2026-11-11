#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    bool ans1=c1[0]==c2[0]&&c1[1]==c2[1],
    ans2=(s1[0]==s2[0]&&s1[1]==s2[1])&&ans1,
    ans3=((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))&&ans2,
    ans4=abs(s1[2]-s2[2])==1&&ans3;
    cout<<ans1<<ans2<<ans3<<ans4<<endl;
    return 0;
}
