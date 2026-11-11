#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],h,jl[500005],sl,minn1,minn2,jj1,jj2,md,jg;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h+=a[i];
	}
	h/=n;
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		if(a[i]<=h){
			sl++;
		}
		jl[i]=abs(h-a[i]);
	}
	minn1=a[sl+1];
	minn2=a[sl+2];
	if(minn1==minn2){
		jj1=2;
	}
	for(int i=sl+3;i<=n;i++){
		if(a[i]==minn1){
			jj1++;
		}
		else if(a[i]==minn2){
			jj2++;
		}
		else{
			break;
		}
	}
	for(int i=sl;i>=1;i--){
		long long ak=minn1-a[i];
		if(m>=ak){
			m-=ak;
			a[i]+=ak;
			jj1++;
		}
		else{
			md=i;
			break;
		}
	}
	for(int i=md;i<=sl+1;i++){
		jg++;
	}
	cout<<jg;
	return 0;
}
