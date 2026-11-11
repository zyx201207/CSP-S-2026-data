#include<bits/stdc++.h>
using namespace std;
const int MX=(1e5+5)*2;
int n,m;
long long a[MX],b[MX];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<m;i++){
		cin>>a[i];
	}
	for(int i=m;i<=n;i++){
		cin>>a[i];
		b[i-m+1]=a[i];
		int x=m-1;
		int y=i-1;
		while(x>0){
			b[i-m+1]&=a[y];
			x--;
			y--;
		}
	}
	long long ans=b[1];
	for(int i=2;i<=n-m+1;i++){
		if(b[i]>ans)  ans=b[i];
	}
	cout<<ans;
	return 0;
}