#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
int a[200005],maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn<<" ";
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			ans=a[1];
			for(int j=2;j<i;j++){
				if(i==1){
					ans=a[2];
					j++;
				}
				if(j==i){
					j++;
				}
				ans=ans&a[j];
			}
		}
	}
	else cout<<1;
	return 0;
} 
