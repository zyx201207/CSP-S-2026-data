#include<bits/stdc++.h>
using namespace std;
#define long long
signed main(){
	int a[100000],n,m,l=1,d=1,q=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int j=1;m>=0;){
		if(a[l]==a[l+1]){
			d+=1;l+=1;q+=1;continue;
		}
		if(m-q>=0){
			a[l]+=1;
		}
		
		if(a[l]==a[l+1]){
			d+=1;l+=1;
			m-=q; q+=1;
		}else{
			m-=q;
		}
	}
	cout<<d;
	return 0;
}