#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,l[5005][505];
long long w[5005];
vector<vector<int>> l1;
int s(int x,int y,int ll){
    for(int i=0;i<l1[x].size();i++){
        for(int j=0;j<l1[y].size();j++){
            if(l1[x][i]==l1[y][j])
                return l[x][l1[x][i]]+l[y][l1[y][j]];
        }
    }
    for(int i=0;i<l1[x].size();i++){
        if(l1[x][i]==ll)continue;
        for(int j=0;j<m;j++){
            if(l[j][l1[x][i]]!=0){
                return l[x][l1[x][i]]+l[j][l1[x][i]]+s(j,y,l1[x][i]);
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    int a,t;
    for(int i=0;i<m;i++)cin>>w[i];
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>a>>t;
            l[a][i]=t;
            l1[a].push_back(i);
        }
    }
    while(q--){
        int x,y,ans=0;
        cin>>x>>y;
        ans+=w[x];
        ans+=w[y];
        ans+=s(x,y,-1);
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
