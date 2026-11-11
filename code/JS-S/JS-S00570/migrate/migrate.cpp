#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,a[5010],dis[310][310],mindis[310],iff[310][310];
vector<int>k[5010];
void dfs(int y,int z){
    //cout<<y<<" "<<z<<endl;
    if(mindis[y]==-1)mindis[y]=z;
    if(mindis[y]<z)return;
    else mindis[y]=min(mindis[y],(long long)z);
    dis[y][z]++;
    for(int i=0;i<k[y].size();i++){
            dfs(k[y][i],z+1);
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        for(int i=1;i<=n;i++){
            for(int j=0;j<k[i].size();j++)k[i][j]=0;
        }
        memset(iff,0,sizeof iff);
        cin>>n>>d;
        int ans=0;
        int l=1,la=0,num=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(la)num+=a[i]-la;
            la=a[i];
            while(num>d){
                num-=(a[l+1]-a[l]);
                l++;
            }
            for(int j=l;j<i;j++){
                    if(iff[j][i]==0)k[j].push_back(i),iff[j][i]=1;
            }
        }
        for(int i=1;i<=n;i++){
        memset(dis,0,sizeof dis);
        memset(mindis,-1,sizeof mindis);
        dfs(i,0);
        for(int j=i+1;j<=n;j++)if(dis[j][mindis[j]]==2)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/


