#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const long long M=1e18+5;
long long m,n,a[N],cnt;
int solve(int x){
	long long minn=M;
	for(int i=x;i<=n;i++){
		cnt=0;
		for(int j=i-x+1;j<i;j++){
			cnt+=a[i]-a[j];
		}
		minn=min(minn,cnt);
	}
	if(minn<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(solve(i)==0){
			cout<<i-1;return 0;
		}
	}cout<<n;
	return 0; 
}


