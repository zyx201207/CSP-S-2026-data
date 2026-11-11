#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cha1;
int op,ans,maxx=INT_MIN,ans1,minn=INT_MAX;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],maxx=max(a[i],maxx),minn=min(minn,a[i]);
    sort(a+1,a+1+n);
    int cha=a[2]-a[1];
    cha1=cha;
    for(int i=1;i<n;i++){
        if(a[i+1]-a[i]!=cha)op=0;
    }
    if(op==1){
        while(m>=cha1){
            ans++;
            m-=cha1;
            cha1+=cha;
        }
        cout<<ans;
    }
    else {
        int b[500005],it;
        for(int i=minn;i<=maxx;i++){
            for(int j=1;a[j]<=i;j++){
                b[j]=i-a[j];
                it=j;
                if(a[j]==i&&a[j+1]!=i)break;
            }
            int tot=m;
            for(int j=it;j>0&&tot>=b[j];j--){
                ans1++;
                tot-=b[j];
            }
            ans=max(ans,ans1);
            ans1=0;
        }
        cout<<ans;
    }
}