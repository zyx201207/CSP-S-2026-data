#include<bits/stdc++.h> 
using namespace std;
long long n,m,ans=-0xffffffff;
long long a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m==n){
		for(int i=0;i<n;i++){
			ans=ans & a[i];
		}
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				long long c=a[i] & a[j];
				ans=max(ans,c);
			}
		}
	}
	if(m==n-1){
		for(int i=n-1;i>=1;i--){
			ans=ans & a[i];
		}
	}
	if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
	}
	cout<<ans;
	return 0;
}
