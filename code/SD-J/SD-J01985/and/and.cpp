#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	long long ans=-1,s;
	if(m==2){
		for(int i=0;i<n;i++){
			s=a[i];
			for(int j=i+1;j<n;j++){
				s&=a[j];
				ans=max(ans,s);
				s=a[i];
			}
		}
		cout<<ans;
	}else if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else{
		ans=a[n-1];
		cout<<ans;
	}
	
	return 0;
}
