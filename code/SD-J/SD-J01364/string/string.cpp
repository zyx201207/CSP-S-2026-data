#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
char c[N];
long long a[N];
long long cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		long long t=min(a[i],a[j]);
		a[i]-=t;
		a[j]-=t;
		if(c[i]!=c[j])cnt+=t;
		if(a[i]==0)i++;
		if(a[j]==0)j--;
	}
	cout<<cnt;
	return 0;
}


