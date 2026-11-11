#include<bits/stdc++.h>
using namespace std;
int n,m;
long long maxn=0,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	for(int i=1;i<=n-m+1;i++){
		long long s=a[i];
		for(int j=i;j<=i+m-1;j++){
//			cout<<a[j]<<" ";
			s&=a[j];
		}
		
	//	cout<<s<<endl;
		maxn=max(maxn,s);
	}
	cout<<maxn;
	return 0;
}
