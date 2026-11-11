#include<bits/stdc++.h>
#include<cstdio>
#include<stdio.h>
using namespace std;
const int N=5e5+5,M=1e12+5;
int n,ans;
long long m;
long long a[N],maxa,mina;
bool flag1=1,flag2=1;
int d;
int gal_add(int x,int d){
	int y,z,l=1;
	for(int i=1;;i+=d){
		if(y+i>x){
			z=l;
			break;
		}
		l++;
		y+=i;
	}
	return z;
}
void dfs(int where,int mofar,int oth,int jz,int cnt){
	if(where==mofar){
		ans=max(ans,cnt);
		return;
	}
	if(oth<a[where]-jz){
		ans=max(ans,cnt);
		return;
	}
	dfs(where+1,mofar,oth-(a[where]-jz),jz,cnt+1);
}
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flag1=0;
	}
	if(flag1){
		cout<<gal_add(m,1);
		return 0;
	}
	d=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=d){
			flag2=0;
		}
	}
	if(flag2){
		cout<<gal_add(m,d);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	mina=a[1];
	maxa=a[n];
	for(int i=mina;i<=maxa;i++){
		int fin=1,sta=1;
		for(;sta<=n;sta++){
			if(a[sta]+m>=i){
				break;
			}
		}
		for(;fin<=n;fin++){
			if(a[fin]>i){
				fin--;
				break;
			}
		}
		dfs(sta,fin,m,i,0);
	}
	cout<<ans;
	return 0;
}