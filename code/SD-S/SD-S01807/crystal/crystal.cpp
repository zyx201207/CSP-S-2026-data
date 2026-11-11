#include<bits/stdc++.h>
using namespace std;
long long n,m,b,ans,c;
long long a[500050],s[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}if(n>5000){
		for(int i=1;i<=n;i++){
			if(a[i]*(i-1)-s[i]+s[b]>m){
				ans=max(c,ans);
				b=i;
				c=0;
			}
			c++;
			if(i==n){
				ans=max(c,ans);
			}
		}cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			c=0;
			for(int j=i;j<=n;j++){
				if(a[j]*(j-i)-s[j-1]+s[i-1]>m){
					ans=max(c,ans);
					c=0;
				}
				c++;
			}if(i==n){
				ans=max(c,ans);
			}
		}cout<<ans;
	}
	return 0;
}
