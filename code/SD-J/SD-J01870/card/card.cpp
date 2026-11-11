#include<bits/stdc++.h>
using namespace std;
#define C ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define ll long long
int a[500005];
bool v[300005];
int b[500005];
int main(){
	C
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]==1;
	}
	ll ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int l=i;l<=n;l++){
				v[a[l]]=0;
			}
			if(v[i]==1){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
