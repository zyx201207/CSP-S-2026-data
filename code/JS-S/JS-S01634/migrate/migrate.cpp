#include <bits/stdc++.h>
using namespace std;
long long n;
long long d;
long long a[200005];
long long dis[200005];
long long ways[200005];
long long f(long long x){
    memset(dis,0x3f,sizeof dis);
    memset(ways,0,sizeof ways);
    long long sum=0;
    queue<long long> q;
    q.push(x);
    dis[x]=1;
    ways[x]=1;
    while(!q.empty()){
        long long f=q.front();
        q.pop();
        for(long long i=f+1;i<=n;i++){
            if(a[f]+d>=a[i]){
                if(dis[f]+1<=dis[i]){
                    if(dis[f]+1<dis[i]){
                        q.push(i);
                    }
                    ways[i]+=ways[f];
                    dis[i]=dis[f]+1;
                }
            }
            else{
                break;
            }
        }
    }
    for(long long i=x;i<=n;i++){
        sum+=ways[i]==2;
    }
    return sum;

}
int main(){
    auto fcin=ifstream("migrate.in");
    auto fcout=ofstream("migrate.out");
    int c,t;
    fcin>>c>>t;
    while(t--){
        fcin>>n>>d;
        for(int i=1;i<=n;i++){
            fcin>>a[i];
        }
        long long sm=0;
        for(int j=1;j<=n;j++){
            sm+=f(j);
        }

        fcout<<sm<<"\n";

    }
    return 0;
}
