#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int w=0,maxx=INT_MIN;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		w&=a[i];
	}
	if(n==m){
		cout<<w;
		return 0;
	}
	else if(m==1){
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			cout<<x&&a[j];
			return 0;
		}
	}
	return 0;
} 
