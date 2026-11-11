#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxx,cnt=1,sum,l,r,mid,zong[500005];
bool f=1;
int sou(long long x){
	for (int i=1;i<x;i++){
		sum+=a[x]-a[i];
		cnt++; 
	}
	if(sum<=m){
		maxx=max(cnt,maxx);
		sum=0,cnt=1;
		return 1;
	}
	sum=0,cnt=1;
	return 0;
}
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long cha=a[2]-a[1];
	for (int i=2;i<=n;i++)
	    if(a[i]-a[i-1]!=cha) f=0;
	    
	if(f==1)
		for (int i=1;i<=n;i++){
			zong[i]=(i*i-i)/2*cha;
			if(zong[i]>m&&zong[i-1]<=m){
			    cout<<i-1;
			    return 0;
			}
		}
		
	for (int i=1;i<=n;i++){
		if(!sou(i)){
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}