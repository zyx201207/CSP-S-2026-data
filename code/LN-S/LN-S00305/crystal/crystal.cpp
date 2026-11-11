#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 600000;

ll m;
ll a[N];
ll suf[N];
int n;

bool check(ll x){
    for(ll i = x;i<=n;i++){
        if((a[i] * x) - (suf[i] - suf[i - x]) <= m)return true;
    }
    return false;
}

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    cin>>n>>m;
    suf[0] = 0;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
		suf[i] = suf[i-1] + a[i];
	}
    int l = 1,r = n;
    while(l < r){
        int mid = l + (r - l + 1) / 2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    cout<<l;
}
