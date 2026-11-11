#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	bool flag=0;
	cin>>n>>m;
	int maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int an=a[i]&a[j];
			maxx=max(maxx,an);
		}
	}
	cout<<maxx;
	return 0;
} 

