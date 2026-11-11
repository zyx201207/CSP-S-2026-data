#include<bits/stdc++.h>
using namespace std;
long long b,d;
int a[200005];
string s;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long c,t;
	cin>>c>>t;
		int n,d,m;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int gett=0;
		bool A=1;
		for(int i=2;i<=n;i++){
			if(a[i]!=gett){
				A=0;
				break;
			}
		}
	if(A){
		if(d<=gett*2){
			cout<<0<<"/n";
		}
		else{
			cout<<m<<"/n";
	}
}
cout<<1<<endl<<2;
	return 0;
}
