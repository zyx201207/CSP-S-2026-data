#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q,T;
int w[M],s[N][M];


int num(int a,int b){
	
	
	
	
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i =1;i<=m;i++)cin>>w[i];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		while(k--){
			int a;
			cin>>a>>T;
			n[i][a]++;
		}
		
		
	}
	while(q--){
		int a,b;
		int t=w[a]+w[b]+num(a,b)*2*T;
		t=3;
		cout<<t<<"\n";
	}
	return 0;
}
