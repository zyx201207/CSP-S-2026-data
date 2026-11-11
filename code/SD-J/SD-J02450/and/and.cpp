#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[200010],ans,f,cc;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>f){
			f=a[i];
		}
		if(a[i]!=i-1){
			cc++;
		}
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}
	else if(m==1){
		ans=f;
	}
	else if(!cc){
		f=n,ans=a[n];
		for(int i=1;i<=m;i++){
			ans&=a[f];
			f--;
		}
	}
	else{
		sort(a+1,a+n+1);
		f=n,ans=a[n];
		for(int i=1;i<=m;i++){
			ans&=a[f];
			f--;
		}
	}
	cout<<ans;
	return 0;
}
