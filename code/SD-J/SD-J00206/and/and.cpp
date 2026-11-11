#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],cnt=1,map1[2010],maxn=0,all;
bool cmp(long long x,long long y){
	int xx,yy,xy=x,yx=y;
	xx=yy=0;
	while(xy!=0){
		if(xy%2!=0) xx++;
		xy/=2;
	} 
	while(yx!=0){
		if(yx%2!=0) yy++;
		yx/=2;
	}
	return xy>yx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1) all=a[i];
		else all=(all&a[i]);
		maxn=max(a[i],maxn);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<all;
		return 0;
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int o=i+1;o<=n;o++){
				maxn=max(maxn,(a[i]&a[o]));
			}
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	long long maxn=0;
	for(int i=1;i<=n-m;i++){
		long long lm=a[i];
		for(int o=i;o<=i+m;o++){
			lm=(lm&a[o]);
		}
		maxn=max(lm,maxn);
	}
	cout<<maxn;
	return 0;
}
