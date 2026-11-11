#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[2]=a[2]-a[1];
	for(int i=3;i<=n;i++) s[i]=s[i-1]+(i-1)*abs(a[i]-a[i-1]);
	int maxn=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(s[j]-s[i]<=m){
				maxn=max(maxn,j-i+1);
			}
		}
	}
	cout<<maxn;
	return 0;
} 
