#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll a[314514];
ll q[314514];
ll T[314514];
ll ans[314514];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		ll le=0,sum=0;
		for(int l=i;l<=n;l++){
			if(T[a[l]]!=0){
				while(q[le]!=a[l]){
					T[q[le]]--;
					sum-=q[le];
					q[le]=0;
					le--;
				}
				T[q[le]]--;
					sum-=q[le];
					q[le]=0;
					le--;
			}
			le++;
			q[le]=a[l];
			T[a[l]]++;
			//for(int i=1;i<=le;i++) cout<<q[i]<<"-";
			//cout<<endl;
			//cout<<le<<" ";
		}
		while(le!=0){
			//cout<<a[le]<<" ";
			//cout<<q[le]<<" ";
			T[q[le]]=0;
			ans[q[le]]++;
			q[le]=0;
			le--;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

