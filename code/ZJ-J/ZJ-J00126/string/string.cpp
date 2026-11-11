#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
char c[200001];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	int l=1,r=n,zl=a[1],yl=a[n];char yc=c[n],zc=c[1];
	while(l<r){
		if(zc!=yc){
			int x=min(zl,yl);
			ans+=x;
			zl=zl-x;
			yl=yl-x;
		}else{
			int x=min(zl,yl);
			zl=zl-x;
			yl=yl-x;
		}
		if(zl==0){
			l++;
			zl=a[l];
			zc=c[l];
		}
		if(yl==0){
			r--;
			yl=a[r];
			yc=c[r];
		}
	}
	cout<<ans<<endl;
	return 0;
}
