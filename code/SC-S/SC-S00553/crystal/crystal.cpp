#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m;
vector<LL>a,s;
inline check(int k){
	for(int i=k;i<=n;i++)
		if(a[i]*k-(s[i]-s[i-k])<=m) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	a.resize(n+4),s.resize(n+4),s[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	stable_sort(a.begin()+1,a.begin()+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int L=1,R=n;
	while(L<=R){
		int M=L+(R-L)/2;
		if(check(M)) L=M+1;
		else R=M-1;
	}
	cout<<L-1;
	return 0;
}