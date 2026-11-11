#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,v[500005],r,a,b,pt[505][505],ans;vector<long long> s[500005],t[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(long long j=0;j<m;j++){
        cin>>v[j];
    }
    for(long long j=0;j<n;j++){
        cin>>r;
        for(long long k=0;k<r;k++){
            cin>>a>>b;a--;s[a].push_back(j);t[a].push_back(b);
        }
    }
    for(long long j=0;j<n;j++){
        for(long long k=0;k<n;k++){
            pt[j][k]=(j==k?0:1e17);
        }
    }
    for(long long j=0;j<m;j++){
        for(long long k=0;k<s[j].size();k++){
            for(long long l=0;l<s[j].size();l++){
                pt[s[j][k]][s[j][l]]=min(pt[s[j][k]][s[j][l]],t[j][k]+t[j][l]);
            }
        }
    }
    for(long long l=0;l<n;l++){
        for(long long j=0;j<n;j++){
            for(long long k=0;k<n;k++){
                pt[j][k]=min(pt[j][k],pt[j][l]+pt[l][k]);
            }
        }
    }
    for(long long j=0;j<q;j++){
        cin>>a>>b;a--;b--;ans=1e17;
        for(long long k=0;k<s[a].size();k++){
            for(long long l=0;l<s[b].size();l++){
                ans=min(ans,t[a][k]+t[b][l]+pt[s[a][k]][s[b][l]]);
            }
        }
        cout<<ans+v[a]+v[b]<<'\n';
    }
}
