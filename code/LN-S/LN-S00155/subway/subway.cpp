#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<int>q1[500005],q2[500005];
long long s[501][501];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,y;
            cin>>x>>y;
            q1[x].push_back(i);
            q2[x].push_back(y);
        }
    }for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j)s[i][j]=LLONG_MAX;
    for(int x=1;x<=n;x++){
        for(int i=0;i<q1[x].size();i++){
            for(int j=0;j<q1[x].size();j++){
                int u1=q1[x][i];
                int u2=q1[x][j];
                int v1=q2[x][i];
                int v2=q2[x][j];
                if(s[u1][u2]>v1+v2) s[u1][u2]=s[u2][u1]=v1+v2;
            }

        }
    }/*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<s[i][j]<<" ";cout<<endl;
    }*/
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i][k]+s[k][j]<s[i][j]) s[i][j]=s[j][i]=s[i][k]+s[k][j];
            }
        }
    }/*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout<<s[i][j]<<" ";cout<<endl;
    }*/
    while(q--){
        int x,y;
        cin>>x>>y;
        long long sum=LLONG_MAX;
        for(int i=0;i<q1[x].size();i++){
            for(int j=0;j<q1[y].size();j++){
                int u1=q1[x][i];
                int u2=q1[y][j];
                int v1=q2[x][i];
                int v2=q2[y][j];
                if(s[u1][u2]+v1+v2<sum) sum=s[u1][u2]+v1+v2;
            }
        }cout<<sum+w[x]+w[y]<<endl;
    }
    return 0;
}
