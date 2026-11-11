#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[200005];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}
		cout << maxn;
	}else if(m==n){
		int maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=a[i]&maxn;
		}
		cout << maxn;
	}else if(m==2){
		int maxn=0,b;
		for(int i=1;i<=n;i++){
			b=0;
			for(int j=i+1;j<=n;j++){
				b=max(b,a[i]&a[j]);
			}
			maxn=max(maxn,b);
		}
		cout << maxn;
	}else{
		int minn=a[1];
		for(int i=2;i<=n;i++){
			if(a[i]<minn){
				minn=a[i];
			}
		}
		cout << minn;
	}
	return 0;
}
