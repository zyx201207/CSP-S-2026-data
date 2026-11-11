#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],mx;
int zh(int l,int r){
	int ans=0,k=1;
	for(int i=l;i<=r;i++){
		ans+=b[i]*k;
		k++;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i]; 
	}
	for(long long i=1;i<n;i++){
		for(long long j=i;j<=n;j++){
			if(zh(i,j)<=m){
				mx=max(mx,j-i+2);
			}
		}
	}
	cout<<mx;
	return 0;
}