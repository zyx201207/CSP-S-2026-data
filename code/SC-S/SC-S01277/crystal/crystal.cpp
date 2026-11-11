#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c[200005];
int n,asw;
long long m,sum;
int r(int re){
	for(int i=0;i<n;i++){
		int p=-100000,y;
		for(int j=0;j<=n-i;){
			if(b[j]>p){
				y=j;
				p=b[j];
			}
			j++; 
		}
		int v;
		v=b[y];
		b[y]=b[n-i];
		b[n-i]=v;
	}
	return re;
}
int f(int p){
	int ans=0;
	for(int i=0;i<n;i++){
		b[i]=p-a[i];
	}
	r(0);
	sum=0;
	for(int i=0;i<n&&sum<=m;i++){
		if(b[i]>=0){
			sum+=b[i];
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("crystal3.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k=-200000,l=200001;
	for(int i=0;i<n;i++){
		if(a[i]>k){
			k=a[i];
		}
		if(a[i]<l){
			l=a[i];
		}
	}
	int g;
	for(int i=l;i<=k;i++){
		g=i+100000;
		c[g]=f(i);
	}
	for(int i=l;i<=k;i++){
		g=i+100000;
		if(asw<c[g]){
			asw=c[g];
		}
	}
	cout<<asw;
	return 0;
}