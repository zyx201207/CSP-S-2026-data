#include<bits/stdc++.h>
using namespace std;
// hub
struct node{int u,v;};
int kpow(int n,int m){
	if(m==0)return 1;
	if(m==1)return n;
	if(m%2==1)return kpow(n,m/2)*kpow(n,m/2)*n;
	return kpow(n,m/2)*kpow(n,m/2);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,q;
	cin>>c>>t;
	while(t--){
		cin>>n>>q;
		int l1[40005]={},l2[40005]={};
		string p1="",p2="";
		node a[50005];
		for(int i=2;i<=n;i++){
			cin>>a[i].u>>a[i].v;
			l1[i]=l1[i-1]+a[i].u;
			l2[i]=l2[i-1]+a[i].v;
		}
		l2[n]=l2[n]*l2[n]/2;
	    l2[n]-=(l1[n]*l1[n]-n-q);
		while(l1[n]){
			p1=char(l1[n]%8+'0')+p1;
			l1[n]/=2;
		}
		while(l2[n]){
			p2=char(l2[n]%8+48)+p2;
			l2[n]/=2;
		}
		if(p1.size()==kpow(2,l1[n-1])/n)cout<<kpow(2,l1[n-1])<<'\n';
		else{
			if(n%2==0)cout<<kpow(2,n)/kpow(2,p2.size())<<'\n';
			else cout<<kpow(2,n)/kpow(2,p1.size()+1)<<'\n';
		}
	}
	return 0;
}
