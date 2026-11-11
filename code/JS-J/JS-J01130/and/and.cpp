#include <bits/stdc++.h>
using namespace std;

int n,m;
long long a[200010];
int ans[32];
int mi(int k){
    long long f=1;
    for (int i=1;i<=k;i++)
        f*=2;
    return f;
}
void dfs(int k,int x){
    if(k==-1){
        long long cnt=0,f=1;
        for (int i=0;i<=30;i++){
            if(ans[i]==1)
                cnt+=f;
            f*=2;
        }
        cout << cnt << endl;
        return ;
    }
    long long f=mi(k);
    int p=lower_bound(a+x,a+n+1,f)-a;
    if(n-p+1>m){
        ans[k]=1;
        for (int i=p;i<=n;i++){
            a[i]-=f;
        }
        sort(a+p,a+n+1);
        dfs(k-1,p);
    }
    if(n-p+1==m){
        long long cnt=a[p];
        for (int i=p;i<=n;i++)
            cnt&=a[i];
        int fx=1;
        for (int i=0;i<=30;i++){
            if(ans[i]==1)
                cnt+=fx;
            fx*=2;
        }
        cout << cnt << endl;
        return ;
    }
    if(n-p+1<m){
        for(int i=p;i<=n;i++)
            a[i]-=f;
        dfs(k-1,x);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a,a+n+1);
    dfs(30,1);
    return 0;
}