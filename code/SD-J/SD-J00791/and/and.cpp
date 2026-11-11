#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])>b)b=(a[i]&a[j]);
		}
	}
	if(m!=1) cout<<b;
	else{
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	return 0;
}
