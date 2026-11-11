#include<bits/stdc++.h>
using namespace std;
int a[200005][31],vis[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,mxlen=0,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        string s="";
        while(x!=0){
            s+=char(x%2+'0');
            x>>=1;
        }
        for(int j=0;j<s.size();j++)
            a[i][j+1]=s[j]-'0';
        mxlen=max(mxlen,int(s.size()));
    }
    for(int i=mxlen;i>=1;i--){
        int sum=0;
        for(int j=1;j<=n;j++)
            if(!vis[j]) sum+=a[j][i];
        if(sum<m) continue;
        for(int j=1;j<=n;j++)
            if(!vis[j]) vis[j]=(a[j][i]==0);
        ans+=(1<<(i-1));
    }
    cout<<ans<<endl;
    return 0;
}
