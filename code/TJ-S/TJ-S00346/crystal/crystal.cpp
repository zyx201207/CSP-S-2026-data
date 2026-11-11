#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i+1]-a[i];
	}
	int k=m;
	int ans=0;
	int i=1;
	while(k>=0){
		k-=b[i];
		ans++;
		i++;
	}
	cout<<ans;
	return 0;
}

