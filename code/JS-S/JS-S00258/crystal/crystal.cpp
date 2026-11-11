#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MAXN=5e5+5;
ll n,m,a[MAXN],pre[MAXN];

bool cmp(ll x,ll y){
    return x<y;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1,cmp);

    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    ll l=1,r=1,maxlen=0;
    ll sub;
    while(r<=n){
        sub=a[r]*(r-l+1)-(pre[r]-pre[l-1]);//cost of l->r
        if(sub<=m){
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        else {
            l++;
        }
    }

    cout<<maxlen;

	return 0;
}
