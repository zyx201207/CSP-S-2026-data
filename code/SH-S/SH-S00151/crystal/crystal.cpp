#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+9;
int n,m;
long long a[N],s[N];
long long sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long testsum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		testsum+=a[i];
	}
	sort(a+1,a+n+1);
	int l=1;
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	for(int i=1;i<=n;i++)s[i]=(s[i]+m);
	int i=1;
	for(i=1;i<n;i++){
		if(s[i]<a[i+1]*i)break;
	}
	cout<<i<<endl;;
	return 0;
}

