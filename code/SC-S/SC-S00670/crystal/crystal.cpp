#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],k=1,ans=1,maxx=INT_MIN;
int main(){	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int j=0;j<n;j++){
		for(int i=0;i<k;i++){
			if(m-a[i+1]+a[i]>=0){
				m=m-a[i+1]+a[i];
				a[i]=a[i+1];
			}
			if(m<0){
				cout<<maxx;
				return 0;
			}
		}
		k++;
		int ans=1;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]){
				ans++;
			}
		}
		if(maxx<ans){
			maxx=ans;
		}
	}
	cout<<maxx;
} 