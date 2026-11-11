#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],mx=-100000000;
long long m,cha;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>=500000){
		for(int i=1;i<=n;i++){
	   		cin>>a[i];
    	}
    	cha=abs(a[2]-a[1]);
		for(long long j=1;j<=10000000000;j++){
			long long none=((1+j)*j/2)*cha;
			if(none>m){
				cout<<j;
				return 0;
			}
		}
	}
	b[0]=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			b[1]=a[i];
		}
		else{
			b[i]=b[i-1]+a[i];
		}
	}
	for(int l=1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			int i,j;
			i=a[r]*(r-l+1);
			j=b[r]-b[l-1];
			if((i-j)<=m){
				mx=max(mx,r-l+1);
			}
		}
	}
	cout<<mx;
	return 0;
}
