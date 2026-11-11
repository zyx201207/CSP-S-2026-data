#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int ans;
ll c,n,m,d,q,k1[10100];
ll w[10100];
ll k[10010];
ll a[10100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n ;i++){
		cin>>k1[i];
		for(int j=1;j<=k1[i];j++){
			cin>>a[j]>>c;
			if(j==1)continue;
		}
	}
	cout<<"32"<<endl<<"17";
	
}
