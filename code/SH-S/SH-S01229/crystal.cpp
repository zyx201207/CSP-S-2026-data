#include<bits/stdc++.h>
using namespace std;
int c[550000],d[550000];
long long m;
int fi(int x,int l,int r){
	if(l==r){
		return l;
	}
	int mid=(l+r)/2;
	if(d[x]-d[mid-1]+m>=c[x]*(x-mid+1)){
		return fi(x,l,mid);
	}else{
		return fi(x,mid+1,r);
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+c[i];
	}
	int mn=-1;
	int q=1;
	for(int i=1;i<=n;i++){
		int t=fi(i,q,i);
		q=t;
		mn=max(mn,i-t+1);
	}
	cout<<mn;
	return 0;
} 

