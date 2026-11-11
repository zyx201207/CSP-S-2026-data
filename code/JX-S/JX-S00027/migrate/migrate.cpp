#include<bits/stdc++.h>
using namespace std;
const int N=5010;
long long a[N],ans;
bool check(int l,int r,int d){
    int mq=a[l],minn=0,sl=0;
     for(int i=l+1;i<=r;i++){
        if(a[i]-mq>d){
            minn++;mq=a[i-1];
        }
     }
     minn++;
     queue<pair<int,int>>q;
     q.push({l,0});
     while(!q.empty()){
        int u=q.front().first,step=q.front().second;q.pop();
        if(u==r&&step==minn) sl++;
        for(int i=u+1;i<=r;i++){
            if(a[i]-a[u]<=d) q.push({i,step+1});
        }
     }
     if(sl==2) return true;
     else return false;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,n;
    scanf("%d%d",&c,&n);
    for(int o=1;o<=n;o++){
        long long m,d;scanf("%ld%ld",&m,&d);
        ans=0;
        for(int j=1;j<=m;j++){
            scanf("%ld",&a[j]);
        }
        for(int i=1;i<=m;i++){
            for(int j=i+3;j<=m;j++){
                int dm=0;
                for(int k=i+1;k<=j;k++){
                    if(a[k]-a[k-1]>d) dm=k;
                }
                if(dm!=0){
                    i=dm;break;
                }
                if(check(i,j,d)){ans++;}
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
