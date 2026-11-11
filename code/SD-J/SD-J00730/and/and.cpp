#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
bool cmp(int a,int b){
	if(__builtin_popcount(a)==__builtin_popcount(b)&&log(a)==log(b)){
		return a>b;
	}
	if(log(a)==log(b)){
		return __builtin_popcount(a)>__builtin_popcount(b);
	}
	return log(a)>log(b);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1,cmp);
	int id;
	int ans;
	for(int i=1;i<=n;i++){
		if(__builtin_popcount(a[i])!=1){
			id=i;
			ans=a[i];
			break;
		} 
	} 
	for(int i=id+1;i<=m;i++){
		ans&=a[i];
	} 
	cout<<ans;
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	return 0;
}

