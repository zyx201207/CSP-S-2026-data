#include<bits/stdc++.h>
using namespace std;
long long n,b,c,d,m,ans,ls;
struct vet{
	long long x;
	bool used;
}a[100005];
string s,ss;
long long dfs(long long lss,long long y){
	long long lsss=0;
	long long zy=lss;
	for(long long j=0;j<n;j++){
		if(!a[j].used){
			lss&=a[j].x;
			lsss=j;
			break;
		}
	}
	for(long long j=lsss+1;j<n;j++){
		if((zy&a[j].x)>lss&&!a[j].used){
			a[lsss].used=false;
			lss=(zy&a[j].x);
			a[j].used=true;
			lsss=j;
		}
	}
	if(y<=m){
		y++;
		lss=dfs(lss,y);
	}
	return lss;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i].x;
		a[i].used=false;
	}
	for(long long i=0;i<n;i++){
		for(long long k=i+1;k<n;k++){
			if(ls<(a[k].x&a[i].x)){
				ls=(a[k].x&a[i].x);
				b=i;
				c=k;
			}
		}
	}
	a[b].used=true;
	a[c].used=true;
	d=3;
	ans=ls;
	if(m==2){
		cout<<ls;
	}
	else if(m==1){
		for(long long i=0;i<n;i++){
			ls=max(ls,a[i].x);
		}
		cout<<ls;
	}
	else{
		dfs(ls,d);
		for(long long i=0;i<n;i++){
			if(a[i].used){
				ans&=a[i].x;
			}
		}
		cout<<ans;
	}
	return 0;
}
