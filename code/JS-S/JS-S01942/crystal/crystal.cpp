#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[500010];
long long cnt;
long long maxx=-10000010;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a,a+n);
    for(int i=n;i>=1;i--){
        int d=m;
        int e=1;
        int g=i;
        cnt=0;
        while(g>0 && d>0){
            if(a[g-1]==a[g]){
                cnt++;
                g--;
            }
            if(a[g-1]+e==a[i]){
                e=1;
                --g;
                --d;
                cnt++;
            }
            else{
                --d;
                ++e;
            }
        }
        maxx=max(cnt,maxx);
    }
    cout<<maxx;
    return 0;
}
