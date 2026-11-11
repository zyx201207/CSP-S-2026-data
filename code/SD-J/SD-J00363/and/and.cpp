#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[200005],maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		int x=a[1];
		for(int i=2;i<=n;i++){
			x=(x&a[i]);
		}
		cout<<x;
		return 0;
	}          
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	return 0;
} 
