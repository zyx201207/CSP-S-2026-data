//SN-J00748  张哲瀚  西安市第八十九中学  
#include <bits/stdc++.h>
using namespace std;
int a[200010];
int b[200010];
int two(int a){
	int x=0;
	while(a){
		a/=2;
		x++;
	}
	return x;
}

bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=two(a[i]);
	}
	int as=0;
	int ans=0;
	int cnn=0;
	int cnt[35];
	for(int i=1;i<n;i++){
		cnt[b[i]]++;
	}
	ans+=a[1];
	for(int i=1;i<=m;i++){
		ans=ans&a[i];
	}
		
	cout<<ans;
	return 0;
}
