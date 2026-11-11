#include<bits/stdc++.h> 
using namespace std;
int n,m,a[1000005],l,x=0,ans=0,e;
int w(int p,int b){
	for(int i=n-b;i>n-b-p;i--){
		if(l>0){
			l=l-a[e]+a[i];
		}
		else{
			return -1;
		}
	}
	return p;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	l=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		e=n-i;
		ans=max(ans,w(i,x));
		if(w(i,x)==-1){
			x+=1;
		}
	}
	cout<<ans;
	return 0; 
} 