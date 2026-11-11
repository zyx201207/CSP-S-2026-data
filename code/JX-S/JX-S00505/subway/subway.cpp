#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	int x=a[(n+1)/2],y=1;
	for(int i=n/2;i>=1;i--){
		m-=x-a[i];
		if(m<=0)break;
		y++;
	}
	for(int i=(n+3)/2;i<=n;i++){
		if(a[i]==x)y++;
	}
	cout<<y;
	return 0;
}
