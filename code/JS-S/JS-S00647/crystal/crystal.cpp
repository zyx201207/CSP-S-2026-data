#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int num[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num+1,num+1+n);
    int maxn=1;
    for(int i=2;i<=n;i++){
        int sum=0;
        for(int j=i-1;j>=1;j--){
            sum+=num[i]-num[j];
            if(sum>m){
                break;
            }
            maxn=max(maxn,i-j+1);
        }
    }
    cout<<maxn;
    return 0;
}
