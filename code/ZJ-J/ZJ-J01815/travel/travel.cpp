#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int ans[5];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c)ans[1]=1;
    if(b[0]==d[0]&&b[1]==d[1]&&ans[1]==1)ans[2]=1;
    if((((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C'))||
       ((b[2]>='D'&&b[2]<='F')&&(d[2]>='D'&&d[2]<='F')))&&ans[2]==1)ans[3]=1;
    if(abs(b[2]-d[2])==1&&ans[3]==1)ans[4]=1;
    printf("%d%d%d%d",ans[1],ans[2],ans[3],ans[4]);
    return 0;
}
