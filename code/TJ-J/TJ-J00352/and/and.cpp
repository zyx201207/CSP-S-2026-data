#include<bits/stdc++.h>
using namespace std;
int f[200005],sum[200005],num,a[200005],l,r,g[200005];
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int d(int x,int y){
	while(x>0&&y>0){
		f[l]=x%2;
	    l++;
	    x/=2;
	    g[r]=y%2;
	    r++;
	    y/=2;
	}
	int m=max(l,r);
	for(int i=m;i>=1;i--){
		if(f[i]==g[i]){
			sum[i]=1;
		}
		else{
			sum[i]=0;
		}
	}
	int t=1;
	for(int i=1;i<=m;i++){
		num+=sum[i]*t;
		t*=2;
	}
	return num;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=-1;
	for (int i=1;i<n;i++){
		if(m==2){
			s=max(s,d(a[i],a[i+1]));
		}
		
	}
	cout<<s;
	return 0;
}
