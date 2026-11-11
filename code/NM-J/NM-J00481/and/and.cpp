#include <bits/stdc++.h>

using namespace std;

long long a[200005];
long long n,m;
long long maxx=0;

long long dfs(long long n,long long sum,long long t){
    if(n==m){
        maxx = max(maxx,sum);
        return maxx;
    }
    for(int i=t+1;i<=n;i++){
        dfs(n+1,sum&a[i],i);
    }
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            maxx = max(a[i],maxx);
        }
        cout<<maxx;
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                maxx = max(maxx,a[i]&a[j]);
            }
        }
        cout<<maxx;
    }else if(m==n){
        maxx = a[1];
        for(int i=2;i<=n;i++){
            maxx = maxx&a[i];
        }
        cout<<maxx;
    }else{
        for(int i=1;i<=n;i++){
            dfs(1,a[i],i);
        }
        cout<<maxx;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
