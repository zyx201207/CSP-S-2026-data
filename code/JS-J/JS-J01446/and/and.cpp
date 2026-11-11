#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxx=a[1],all=a[1];
	for(int i=2;i<=n;i++){
		maxx=max(maxx,a[i]);
		all=((a[i])&all);
	}
	int maxxx=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((a[i]&a[j])>maxxx)maxxx=a[i]&a[j];
		}
	}
	if(m==1)cout<<maxx;
	if(m==n)cout<<all;
	if(m==2)cout<<maxxx;
	return 0;
}
