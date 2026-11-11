#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=1,ma=0,sum=0;
	while(l<=n && r<=n){
		sum=((r-l+1)*a[r])-(s[r]-s[l-1]);
		if(sum<=m){
			ma=max(ma,r-l+1);
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ma;
	return 0;
} 