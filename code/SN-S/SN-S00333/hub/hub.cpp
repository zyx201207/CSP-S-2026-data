//李方骁 西安交通大学附属中学 SN-S00333
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
int n,k;
int nn;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;++i){
			int u,v;
			cin>>u>>v;
		}
		nn=(n-1)/2;
		if(k==n)cout<<0<<'\n';
		else{
			nn=nn/2;
			nn++;
			k--;
			while(k>=2){
				nn=nn/2;
				nn++;
				k-=2;
			}
			if(k==1){
				nn--;
			}
			cout<<nn;
		}
	}
	return 0;
}

