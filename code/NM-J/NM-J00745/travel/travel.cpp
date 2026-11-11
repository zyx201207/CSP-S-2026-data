#include <bits/stdc++.h>
using namespace std;
int c1,c2,a1,a2;
int ans[5]={0,0,0,0};
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    char a1=s1[2],a2=s2[2];
    if(c1==c2)ans[0]=1;
    if(s1[0]==s2[0]&&s1[1]==s2[1])ans[1]=1;
    if(a1-'C'>=0&&a2-'C'>=0)ans[2]=1;
    if(a1-'C'<0&&a2-'C'<0)ans[2]=1;
    if(abs(a1-a2)==1)ans[3]=1;
    for(int i=0;i<=3;i++){
        cout<<ans[i];
        if(ans[i]==0)ans[i+1]=0;
    }
    return 0;
}
