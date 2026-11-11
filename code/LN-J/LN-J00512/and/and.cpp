#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],sum,ans,maxx,s[4];
bool flag=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) sum=a[i];
		else sum=(sum&a[i]);
		maxx=max(a[i],maxx);
		if(a[i]>=4) flag=0;
	}
	if(m==n){cout<<sum;return 0;}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			ans=max(ans,(sum&a[i]));
		}
		cout<<ans;
		return 0;
	}
	if(m==1){cout<<maxx;return 0;}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(flag==1){
		for(int i=1;i<=n;i++){
			s[a[i]]++;
		}
		if(s[3]>=m){cout<<3;return 0;}
		if(s[3]+s[2]>=m){cout<<2;return 0;}
		if(s[3]+s[1]>=m){cout<<1;return 0;}
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	cout<<a[m];
	return 0;
}
