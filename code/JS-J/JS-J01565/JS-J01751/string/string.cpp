#include <bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	bool f=1;
	for(long long i=1;i<n;i++){
		if(b[i]!=b[i+1]) f=0;
	}
	if(f){
		cout<<0;
		return 0;
	} 
	long long i=1,j=n;
	long long need=0;
	long long ans=0;
	while(i<j){
		if(a[i]<a[j]){
			need=a[j]-a[i];
			if(b[i]!=b[j]) ans+=a[i];
			i++;
			while(a[i]<=need&&i<j){
				need-=a[i];
				if(b[i]!=b[j]) ans+=a[i];
				i++;
			}
			if(need){
				if(b[i]!=b[j]) ans+=need;
				need=0;
				i++;
			}
		}
		else if(a[i]>a[j]){
			need=a[i]-a[j];
			if(b[i]!=b[j]) ans+=a[j];
			j--;
			while(a[j]<=need&&i<j){
				need-=a[j];
				if(b[i]!=b[j]) ans+=a[j];
				j--;
			}
			if(need){
				if(b[i]!=b[j]) ans+=need;
				need=0;
				j--;
			}
		}
		else{
			if(b[i]!=b[j]){
				ans+=a[i];
			}
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
