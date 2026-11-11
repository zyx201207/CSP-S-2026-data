#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+1;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int maxn=0,n,m,s=0;int maxm;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
	}
	else{
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
			maxm=i;
		}
		for(int i=1;i<=n;i++){
			if(i==maxm) continue;
			s=max(s,a[i]);
		}
		maxn=s;
	}
	cout<<maxn;
	return 0;
}
