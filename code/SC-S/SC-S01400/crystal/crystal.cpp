#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int main(){
	freopen("crystal.in" ,"r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+1+n); 
	long long r=1;
	long long l=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		if((a[i]*(i-r))-(b[i-1]-b[r-1])<=m){
			 ans=max(ans,i-r+1ll);
		}
		else{
			while((a[i]*(i-r))-(b[i-1]-b[r-1])>m&&r<=i){
				++r;
			}
		 ans=max(ans,i-r+1ll);
		}
	}
	cout <<ans;
	return 0;
}
