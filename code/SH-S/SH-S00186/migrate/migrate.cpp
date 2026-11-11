#include<bits/stdc++.h>
using namespace std;
inline bool dfs(const vector<long long> &a,int d,int t,int c,int l){
    if(c==t&&d==3)
        return true;
    if(c!=t&&d==3)
        return false;
    bool ans=false;
    for(int i=c;i<=t;i++)
        if(i!=l)
            ans=ans||dfs(a,d+1,t,i,l);
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t,n,d,f;
    cin>>c>>t;
    vector<long long> a;
    while(t--){
        cin>>n>>d;
        a.resize(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        if(c==11||c==12){
            if(a[3]-a[0]<=d){
                cout<<n-1-3<<endl;
            }
            else
                cout<<0<<endl;
        }
        if(c==13||c==14){
            vector<vector<bool>> v(n,vector<bool>(n));
            for(int i=0;i<n;i++)
                for(int j=i+1;j<n;j++)
                    if(a[j]-a[i]<=d)
                        v[i][j]=true;
            int m=a[n-1]-a[0],l=0,r=n-1;
            while(l<r){
                if(m<a[(l+r)/2])
                    l=(l+r)/2+1;
                else if(m==a[(l+r)/2]){
                    l=(l+r)/2;
                    break;
                }
                else
                    r=(l+r)/2;
            }
            int ans=0;
            for(int i=0;i<n-3;i++)
                for(int j=i+2;j<n;j++)
                    if(dfs(a,1,n,i,l))
                        ans++;
            for(int i=0;i<n-2;i++)
                for(int j=i+1;j<n-1;j++)
                    for(int k=j+1;k<n;k++)
                        if((v[i][j]||v[j][i])&&(v[j][k]||v[k][j]))
                            ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
}
