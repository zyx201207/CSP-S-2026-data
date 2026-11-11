#include <bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],b[N];
int main(){
	freopen("and1.in*","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=0,t=1;
		while(a[i]!=0){
			x+=a[i]%2*t;
			a[i]/=2;
			t*=10;
		}
		b[i]=x;
		cout<<b[i]<<' ';
	}
	cout<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=b[i];
		for(int j=1;j<=m;j++){
			x=x&b[i];
		}
		
		if(x>ans)ans=x;
	}
	cout<<ans;
	return 0;
}