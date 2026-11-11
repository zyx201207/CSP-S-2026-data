#include<bits/stdc++.h>
using namespace std;

long long int c,n,m,d,q,k[555],w[505050],sum,;
int a[505][505050];
int road(){
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int a111,t;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a111>>t;
			a[i][a111]=t;
		}
	}
	while(q--){
		int from,to;
		cin>>from>>to;
		sum=0;
		sum+=w[from];
		sum+=w[to]; 
		cout<<abs(from-to)*t+sum;
	}
	return 0;
} 
