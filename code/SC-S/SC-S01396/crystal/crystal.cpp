#include<bits/stdc++.h>
using namespace std;
long long a[500002];
long long b[500002];
int _max=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		memset(b,0,sizeof(b));
		for(int j=0;j<i;j++){
			b[j]=a[i]-a[j];
		}
		long long mm=m;
		int ans=0;
		while(mm>=0&&i-ans>=0){
			mm-=b[i-1-ans];
			ans++;
		}
		_max=max(_max,ans);
	}
	cout<<_max;
	return 0;
} 