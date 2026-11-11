#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],build1[2 << 21],ans,vis[2 << 21],kkk,kk,maxv,fr[300005],ba[300005];
bool flag;
map<long long ,long long > cnt;
void build(long long num){
    if(build1[num] >= m) ans = max(ans,num);
    long long val = 1;
    while(val <= num){
        if(num & val && vis[num-val] != kkk){
            vis[num-val] = kkk;
            build1[num-val]+=cnt[kkk];
            build(num-val);
        }
        val <<= 1;
    }
    return;
}
long long ff(long long h){
    if(h % 2 == 1) return h;
    else return ff(h/2);
}
bool cmp(long long x,long long y){
    return x > y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(vis,-1,sizeof(vis));
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(ff(a[i]+1) != 1){
            flag = true;
        }
        cnt[a[i]]++;
        maxv = max(a[i],maxv);
    }
    if(flag == false){
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
        return 0;
    }
    if(m == 1){
        cout<<maxv;
        return 0;
    }
    else if(m == n){
        ans = a[1];
        for(long long j=2;j<=n;j++){
            ans = (ans & a[j]);
        }
        cout<<ans;
        return 0;
    }
    else if(m == 2){
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                ans = max(ans,(a[i] & a[j]));
            }
        }
        cout<<ans;
        return 0;
    }
    else if(m == n-1){
        for(long long i=1;i<=n;i++){
            if(i == 1) fr[i] = a[i];
            else{
                fr[i] = (a[i] & fr[i-1]);
            }
        }
        for(long long i=n;i>=1;i--){
            if(i == n) ba[i] = a[i];
            else{
                ba[i] = (a[i] & ba[i+1]);
            }
        }
        for(long long i=1;i<=n;i++){
            if(i == 1){
                ans = max(ans,ba[i+1]);
            }
            else if(i == n) ans = max(ans,fr[i-1]);
            else{
                ans = max(ans,(fr[i-1] & ba[i+1]));
            }
        }
        cout<<ans;
        return 0;
    }
    for(auto it = cnt.begin();it != cnt.end();it++){
        kkk = it->first;
        build1[kkk]+=it->second;
        build(kkk);
    }
    cout<<ans;
    return 0;
}
