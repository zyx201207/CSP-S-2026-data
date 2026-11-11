#include<bits/stdc++.h>
using namespace std ;
int a[1000005];
int b[1000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int maxn=-1e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int ans=a[i]&a[j];
				maxn=max(ans,maxn);
			}
		}
		cout<<maxn<<endl;
	}
	return 0;
}
