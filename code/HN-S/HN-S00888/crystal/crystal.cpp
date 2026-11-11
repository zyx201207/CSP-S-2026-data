#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],ta=1,dc,mina=INT_MAX,x[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long sum=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mina=min(mina,a[i]);
		if(a[i]!=i)ta=0; 
	}dc=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]==dc){
			ta=2;
		}
	}
	if(ta==1||(ta==2&&dc==1)){
		int r=1;
		while(m>r){
			m-=r;
			r++;
		}
		if(m==0){
			cout<<r+1;
		}else{
			cout<<r;
		}
	}else{
		while(sum>0){
			for(int i=1;i<=n;i++){
				if(a[i]==mina){
					a[i]++;
					sum--;
				}
			}mina++;
		}long long maxa=0;
		for(int i=1;i<=n;i++){
			x[a[i]]++;
			maxa=max(x[a[i]],maxa);
		}
		if(sum==0)cout<<maxa;
		else cout<<maxa-1;
	}
	return 0;
}  
