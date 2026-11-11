#include <bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n,m,ans,cnt;
int a[N];
struct A{
    int num,x;
}b[N];
struct B{
    int kk, sum,res,len;
} bb[N];
void solve(int k){
    int sum=0,res=b[k].num,kk=k;
    if(bb[k+1].sum!=0){
        sum=bb[k+1].sum-(b[k+1].x-b[k].x)*(bb[k+1].len-b[k+1].num);
    }if(bb[k+1].res!=0){
        res=bb[k+1].res-b[k+1].num;
    }if(bb[k+1].kk!=0){
        kk=bb[k+1].kk+1;
    }
    for(int i=kk;i>=2;i--){
        int d = b[k].x - b[i - 1].x;
        sum += d * b[i - 1].num;
        if(sum>m){
            int gs = (sum - m + d - 1) / d;
            res += b[i - 1].num - gs;
            ans = max(ans, res);
            return;
        }
        bb[k].kk=i;
        bb[k].sum=sum;
        bb[k+1].res=res;
        res += b[i - 1].num;
    }
    ans = max(ans, res);
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m ;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);//nlogn
    for(int i=1;i<=n;i++){
        if((a[i]!=a[i-1]) || (i==1)){
            b[++cnt].x=a[i];
        }
        b[cnt].num++;
    }
    for (int i = 1; i <= cnt; i++){//n
        solve(i);
    }
    cout << ans << endl;
    return 0;
}