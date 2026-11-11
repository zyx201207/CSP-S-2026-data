#include <iostream>
#include <cstring>
using namespace std;
const int N=5e5+7;
int n,m;
int a[N];
int q[N];
int ans[N];
bool w=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			w=false;
		}
	}
	if(w){
		for(int i=2;i<=n+1;i++){
			if(a[i]!=a[i-1]){
				ans[a[i-1]]=i-1;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int idx=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=idx;k++){
				if(q[k]==a[j]){
					idx=k-1;
					break;
				}
			}
			q[++idx]=a[j];
		}
		for(int j=1;j<=idx;j++){
			if(q[j]<=m){
				ans[q[j]]+=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
