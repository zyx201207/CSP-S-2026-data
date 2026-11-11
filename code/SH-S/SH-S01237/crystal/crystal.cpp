#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5+5;
int n,m,a[N],ans=-1;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i <= n;i++){
        int t=m,res = 1;
        for(int j=i-1;j >= 1;j--){
            int del = a[i]-a[j];
            if(t-del>=0){
                t-=del;
                res++;
            }else{
                break;
            }
        }
        ans = max(ans,res);
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
