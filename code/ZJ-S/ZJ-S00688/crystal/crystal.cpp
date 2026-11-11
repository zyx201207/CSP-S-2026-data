#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
bool b1=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&i!=2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
			b1=false;
		}
	}
	if(b1){
		sort(a+1,a+n+1);
		int p=a[2]-a[1];
		cout<<int(sqrt(m*2)/p+1);
	}
	return 0;
}