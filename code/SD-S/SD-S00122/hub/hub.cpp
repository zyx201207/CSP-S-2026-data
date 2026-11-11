#include<iostream>
using namespace std;
int c,t,n,m;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		for(int j=1;j<=n;j++){
			int h,d;
			cin>>h>>d;
		}
		cout<<n/m+1<<"\n";
	}
	
	return 0;
} 
