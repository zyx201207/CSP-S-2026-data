#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],maxn=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n;j++){
			if(i!=j){
				int t=a[i]&a[j];
//				cout<<t<<' '<<i<<' '<<j<<"\n";
				maxn=max(maxn,t);
			}
		}
	}
	cout<<maxn;
	return 0;
}
