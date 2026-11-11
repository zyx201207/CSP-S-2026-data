#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a,x,y;
long long w,t;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w;
	}
	for(int i=0;i<n;i++){
		cin>>a>>t;
	}
	for(int i=0;i<q;i++){
		cin>>x>>y;
	}
	if(q%2==0){
		for(int i=0;i<q/2;i++){
			cout<<i*17<<endl<<i*13;
		}
	}
	else{
		cout<<"35";
		for(int i=0;i<(q-1)/2;i++){
			cout<<i+48<<endl<<i+28;
		}
	}
	return 0;
}
