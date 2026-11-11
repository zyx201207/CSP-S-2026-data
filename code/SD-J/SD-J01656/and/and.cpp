#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],b[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}else if(m==2){
		int maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				int cnt=0,l=0;
				while(a[i]!=0||a[j]!=0){
					int t=a[i]%2;
					int w=a[j]%2;
					if(t==w&&t==1){
						cnt++;
						l+=cnt*2;
					}	
				}
					maxx=max(maxx,a[i]);
			}
		}
		cout<<maxx;
		return 0;
	}else{
		int l=a[1],cnt=0;
		for(int i=2;i<=n;i++){
			cnt=0;
			int k=0;
			while(a[i]!=0||l!=0){
					int t=a[i]%2;
					int w=l%2;
					if(t==w&&t==1){
						cnt++;
						k+=cnt*2;
					}	
			}
			l=k;
		}
		cout<<l;
	}
	return 0;
}

