#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int u[500005],v[500005];
int cnt;
int mn=INT_MAX;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>u[i]>>v[i];
			cnt+=min(u[i],v[i])/n;
			if(cnt<mn)mn=cnt;
		}
		cout<<mn<<endl;
	}
	return 0;
}
