#include<bits/stdc++.h> 
#include<cstdio>
using namespace std;
int const maxn=200002;
int a[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		int maxa=-1;
		for(int i=1;i<=n;i++){
			maxa=max(maxa,a[i]);
		}
		cout << maxa;
		return 0;
	}
	if(m==n){
		int b=a[1];
		for(int i=2;i<=n;i++){
			b&=a[i];
		}
		cout << b;
		return 0;
	}
	if(m==2){
		int maxb=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxb=max(maxb,a[i]&a[j]);
			}
		}
		cout << maxb;
		return 0;
	}if(m==(n-1)){
		int b=a[2];
		for(int i=3;i<=n;i++){
			b&=a[i];
		}
		int maxb=b;
		b=a[1];
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					b&=a[j];
				}
			}
			maxb=max(maxb,b);
		}
		cout << maxb;
		return 0;
	}
	int maxa=-1;
		for(int i=1;i<=n;i++){
			maxa=max(maxa,a[i]);
		}
		cout << maxa;
	return 0;
}
