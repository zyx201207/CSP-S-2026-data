#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[500005];
int ls[50005];
struct node{
    int a[502];
    int q[502];
    int h[502];
    int xl=0;
}line[50005];
int dfs(int dia,int cost,int xianlu){
    if(dia==y)return cost+w[y];
    if(line[dia].h[xianlu]==-1)return -1;

}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++)cin>>w[i];
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        for(int j=0;j<t;j++){
            memset(ls,0,sizeof(ls));
            line[ls[j]].xl++;
            cin>>ls[j];
            cin>>line[ls[j]].a[i];
            if(j==0)line[ls[j]].q[i]=-1;
            if(j==t-1)line[ls[j]].h[i]=-1;
            else {
                line[ls[j]].q[i]=ls[j-1];
                line[ls[j-1]].h[i]=ls[j];
            }
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<w[x]+w[y]+line[1].a[x]+line[1].a[y];

    }

    fclose(stdin);
    fclose(stdout);
}
