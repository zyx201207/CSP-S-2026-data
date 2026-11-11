#include<bits/stdc++.h>
using namespace std;
int c,t1;
struct shj{
    int n;
    long long d;
}t[100010];
void solve(int p,int q){
    vector<long long> x(p,0);
    long long sum=0;
    int flag=0;
    for(int i=0;i<p;i++) scanf("%lld",&x[i]);
    for(int i=1;i<=p;i++){
        for(int j=i+1;j<=p;j++){
            if(x[j]-x[i]<=q or q==1) flag=0;
            else if((x[j]-x[i])%q==0) flag=0;
            else{
                int m[100010];

            }
            if(flag==1) sum+=1;
        }
    }
    printf("%lld",sum);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t1);
    for(int i=1;i<=t1;i++){scanf("%d%lld",&t[i].n,&t[i].d); solve(t[i].n,t[i].d);}
}
