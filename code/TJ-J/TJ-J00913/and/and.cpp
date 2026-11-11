#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long s=1,ans,mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s=s&a[i];
		mx=max(mx,a[i]);
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<s;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			s=1;
			for(int j=1;j<=n;j++){
				if(i!=j)s=s&a[j];
			}
			ans=max(ans,s);
		}
		cout<<ans;
		return 0;
	}
	mx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mx=max(mx,a[i]&a[j]);
		}
	}
	cout<<mx;
	return 0;
}
