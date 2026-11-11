#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
long long n,m,ans=0,s;
long long  a[N];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=m;i++){
		s=a[i];
		if(s-a[i+1]>=0&&a[i+1]-s<=m)
		{
			a[i]++;
			if(a[i+1]==s)
			ans++;
		}
		
	}
	cout<<ans;
	return 0; 
} 
