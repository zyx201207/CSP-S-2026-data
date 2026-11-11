#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500001],h,c1,c2,flag=1;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i],h+=a[i];
		if(i!=1 && flag){
			if(i==2) c1=a[i]-a[i-1];
			else{
				c2=c1,c1=a[i]-a[i-1];
				if(c1!=c2) flag=0;
			}
		}
	}
	sort(a+1,a+1+n,cmp);
	if(flag){
		m/=c1;
		int i;
		for(i=1;m>=0;i++) m-=i;
		cout<<i-1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]*(n-i+1)-h<=m){
			cout<<n-i+1;
			break;
		}
		h-=a[i];
	}
	return 0;
}
