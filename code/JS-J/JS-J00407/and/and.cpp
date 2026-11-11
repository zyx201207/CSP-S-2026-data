#include<bits/stdc++.h>
using namespace std;
int a[200005][32],ans[32];
int main(){
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,t,y=-1,m,x;cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>t;
        x=0;
        while(t>0){
            a[i][x]=t%2;x++;t/=2;
        }
        y=max(x,y);
    }
    int cnt=0;
    for(int i=y-1;i>=0;--i){
        cnt=0;
        for(int j=1;j<=n;++j){
            bool b=1;
            for(int k=y-1;k>=i;--k){if(ans[k]==1&&a[j][k]==0){b=0;break;}}
            if(a[j][i]==1&&b)cnt++;
        }
        if(cnt>=m)ans[i]=1;
    }
    int c=31,d=0;
	for(int i=c;i>=0;--i)d=d*2+ans[i];
    cout<<d;
    return 0;
}
