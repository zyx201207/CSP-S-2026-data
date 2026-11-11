#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],b[N];
int n,m,maxxxx=-1;
void dg(int x,int cnt){
	b[cnt]=a[x];
	if(cnt==m){
		int sum;
		for(int i=1;i<=cnt;i++){
			if(i==1) sum=b[i];
			else sum=sum&b[i];
		}
		maxxxx=max(maxxxx,sum);
		return;
	}
	for(int i=x+1;i<=n;i++){
		dg(i,cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int yfnm,maxx=-1;
	bool flag1=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) flag1=false;
		if(i==1) yfnm=a[i];
		else yfnm=yfnm&a[i];
		maxx=max(maxx,a[i]);
	}
	if(flag1){
		cout<<n-m;
		return 0;
	}
	if(m==n){
		cout<<yfnm;
		return 0;
	}else if(m==1){
		cout<<maxx;
		return 0;
	}else if(m==2){
		int maxxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxxx=max(maxxx,a[i]&a[j]);
			}
		}
		cout<<maxxx;
		return 0;
	}
	dg(1,1);
	cout<<maxxxx;
	return 0;
}
