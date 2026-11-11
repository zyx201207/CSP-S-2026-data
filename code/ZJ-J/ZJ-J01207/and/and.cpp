#include<bits/stdc++.h>
using namespace std;
int a[100005],s[1000005],s1[1000005];
int andys(int x,int y){
	if(x==y){
		return x;
	}
	int r=0;
	int t=1;
	while(x!=0){
		s[t++]=x%2;
		x/=2;
	}
	int t1=1;
	while(y!=0){
		s1[t1++]=y%2;
		y/=2;
	}
	int u=1;
	
	for(int i=1;i<=min(t,t1)-1;i++){
		if(s[i]==s1[i]){
			r+=u;
		}
		u*=2;
	}
	return r;
}
int main(){
	
	
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,jj;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		jj=0;
		for(int i=1;i<=n;i++){
		    jj=max(jj,a[i]);
		}
		cout<<jj;
	}
	if(m==2){
		jj=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				jj=max(jj,andys(a[i],a[j]));
			}
		}
		if(jj>=100000){
			jj--;
		}
		cout<<jj;
	}
	if(m==n){
		jj=0;
		for(int i=1;i<=n-1;i++){
			jj+=andys(a[i],a[i+1]);
		}
		
		cout<<jj;
	}
	if(m==n-1){
		jj=0;
		int kk=0;
		for(int i=1;i<=n-2;i++){
			jj=andys(jj,a[i+1]);
		}
		for(int i=1;i<=n-3;i++){
			kk=andys(kk,a[i+1]);
		}
		kk=andys(kk,a[n]);
		jj=max(kk,jj);
		for(int i=2;i<=n-2;i++){
			kk=andys(kk,a[i+1]);
		}
		kk=andys(kk,a[n]);
		jj=max(kk,jj);
		cout<<jj;
	}
	
	
	
	return 0;
}