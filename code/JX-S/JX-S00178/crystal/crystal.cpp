#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1,cmp);
    long long maxn=-999;
    for(int i=1;i<=n;i++){
        long long ans=0;
        int m2=m;
        for(int j=i;j<=n;j++){
            if(m2>=a[i]-a[j]){
                //cout << "ans++" << ' ' << a[i]-a[j] << ' ';
                m2-=a[i]-a[j];
                ans++;
            }
            else{
                break;
            }
        }
        //cout << ans << endl;
        maxn=max(maxn,ans);
    }
    cout << maxn;
    return 0;
}
