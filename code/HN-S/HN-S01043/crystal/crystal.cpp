#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long a[maxn];
int n,ans=0;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		a[i]=a[i+1]-a[i];
	}
	for (int i=1;i<=n;i++){
		int cnt=1,j=i,x=m;
		while (x>=0 && j<=n){
			x-=a[j]*(j-i+1),cnt++;
			j++; 
		}
		cnt-=1; 
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
