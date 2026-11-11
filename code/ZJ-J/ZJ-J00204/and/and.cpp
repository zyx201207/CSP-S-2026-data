#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],f[N][40],c[40];
bool st[40],sr[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
		return 0;
	}
	else if(m==n){
		int c=a[1]&a[2];
		for(int i=3;i<=n;i++){
			c=c&a[i];
		}
		cout<<c;
		return 0;
	}
	else if(m==2){
		int ma=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	else if(m==n-1){
		int ma=0;
		for(int i=1;i<=n;i++){
			int clx=0;
			if(i!=1) clx=a[1];
			else clx=a[2];
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				clx=clx&a[j];
			}
			ma=max(clx,ma);
		}
		cout<<ma;
		return 0;
	}
	else cout<<"0";
	return 0;
}