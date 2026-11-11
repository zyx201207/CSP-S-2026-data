#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MAXN=5005,MAXM=3005;
ll m,n;
ll cip[MAXN],c[MAXN],ct;
ll ans[MAXM];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>cip[i];
    }

    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            ct++;
            c[ct]=cip[j];
            ll last=ct-1;
            while(last>=1){
                if(c[last]==c[ct]){
                    ct=last;
                    break;
                }
                last--;
            }
        }
        for(ll j=1;j<=ct;j++){
            ans[c[j]]++;
        }
        ct=0;
    }

    for(ll i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }

	return 0;
}
