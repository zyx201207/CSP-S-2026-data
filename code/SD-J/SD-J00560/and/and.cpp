#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=INT_MAX;
long long a[200005];
int two(long long x){
	int cnt;
	while(x>0){
		cnt+=x%2;
		x/=2;
	}
	return cnt;
}
bool cmp(long long x,long long y){
	if(x==y){
		return two(x)>two(y);
	}
	else{
		return x>y;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
} 
