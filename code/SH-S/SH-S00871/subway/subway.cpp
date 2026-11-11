#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010];
struct Stop{
	int s,n;
}stop[1000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int sum;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		sum+=k;
		for(int j=0;j<k;j++){
			cin>>stop[k].s>>stop[k].n;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		if(stop[x].n==stop[y].n){
			cout<< w[x]+w[y]+stop[x].s<<endl;
		}
		else{
			if(stop[x+1].n==stop[y].n)
				cout<< w[x]+w[y]+stop[x].s+stop[x+1].s+w[x+1];
		}
	}
	return 0;
}

