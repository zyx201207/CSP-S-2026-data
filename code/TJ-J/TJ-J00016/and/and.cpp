#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int cnt=a[i];
		for(int j=i+1;j<=i+m+1;j++){
			cnt=cnt&a[j];
		}
		if(cnt>=mx){
			mx=cnt;
		}
	}
	cout<<mx;
	return 0;
} 
