#include<bits/stdc++.h>
using namespace std;
int n,mx1,mmx1,ms=0,mms=0;
long long m,x,mx,a[500005]; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal/3.in","r",stdin);
	freopen("crystal/3.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(x!=a[i]){
			mms=0;
			mmx1=i;
		}
		mms++;
		x=a[i];
		if(ms<mms){
			if(mx!=x)mx1=mmx1;
			ms=mms;
			mx=x;
		}
	}
	if(ms==1) mx=a[n];mx1=n;
	if(ms==n){
		cout<<n;
		return 0;
	}
	while(mx1>1){
		mx1--;
		if(m<mx-a[mx1]) break;
		m-=mx-a[mx1];
		a[mx1]+=mx-a[mx1];
		ms++;
	}
	if(mx1==1 && mx!=a[n]){
        while(m>=(a[ms+1]-mx)*ms && ms<n){
        	m-=(a[ms+1]-mx)*ms;
        	ms++;
		}
	}
	cout<<ms;
	return 0;
} 
