#include<bits/stdc++.h>
using namespace std;
int a[200013],qu[200013],n,m,maxd=-8000;
int calc(int l,int r){
	int u=a[l];
	for(int i=l+1;i<=r;i++){
		u&=a[i];
	}
	return u;
}
void fg(int iy,int geshu){
	if(geshu==m){
		int op=qu[1];
		for(int i=1;i<=m;i++){
			op&=qu[i];
		}
		maxd=max(maxd,op);
		return;
	}
	for(int i=iy;i<=n;i++){
		qu[++geshu]=a[i];
		fg(iy+1,geshu);
		qu[geshu--]=0;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			maxd=max(maxd,a[i]);
		}
		cout<<maxd;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxd=max(maxd,a[i]&a[j]);
			}
		}
		cout<<maxd;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			maxd&=a[i];
		}
		cout<<maxd;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			int t=a[1];
			t&=calc(2,i-1);t&=calc(i+1,n);
			maxd=max(maxd,t);
		}
		cout<<maxd;
		return 0;
	}
	fg(1,0);
	cout<<maxd;
	return 0;
}

