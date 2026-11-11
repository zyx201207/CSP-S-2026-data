#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[50010];
int ans,check,s;

int main(){
	freopen("crystal".in,"r",stdin);
	freopen("crystal".out,"w",stdout);
	
	cin >>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i];
		sort(a+1,a+n+1);
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=n){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
	}
	cout <<ans<<endl;
	return 0;
}