#include<bits/stdc++.h>
using namespace std;
long long maxx,maxxx,n,m,a[100005],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		if(i==1){
			ans=a[i];
		}
		else{
			ans=ans&a[i];
		}
	}
	if(m==1){
		cout<<maxx;
	}
	else if(m==n){
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxxx=max(maxxx,(a[i]&a[j]));
				
			}
		}
		cout<<maxxx;
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}

