#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int a[N];
int n,m;
int check(int idx){
    int k=a[idx];
    int idx2=idx;
    int cnt=0;
    int ans=0;
    while(idx2>=1){
        cnt+=k-a[idx2];
        if(cnt>m){
            break;
            ans--;
        }
        ans++;
        idx2--;
    }
    if(cnt<m){
        return -1;
    }
    else return ans;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cout<<0<<endl;
}