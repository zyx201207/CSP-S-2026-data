#include<bits/stdc++.h>
using namespace std;
int jisuan(int i,int www){
	int ww=1,j=0;
	while(ww<=www && i){
		if(i&1) j++;
		i>>=1;
		ww++;
	}
	if(ww<www) return 0;
	return j;
}
struct ff{
	int one;
	int shu;
};
ff g[200005];
int a[200005],n,m,w,aa;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	aa=a[n-m+1];
	while(aa){
		aa/=2;
		w++;
	}
	for(int i=1;i<=n;i++){
		g[i].shu=a[i];
		g[i].one=jisuan(a[i],w);
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			ff l=g[j];
			if(g[j].one>g[j+1].one){
				g[j]=g[j+1];
				g[j+1]=l;
			}
		}
	}
	int sum=g[n].shu;
	for(int i=n-1;i>=n-m+1;i--){
		sum&=g[i].shu;
	}
	cout<<sum;
	return 0;
} 
