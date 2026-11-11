#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b){
	return a>=b;
}
int main(){
	long long n,m;
	long long a[10010];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
