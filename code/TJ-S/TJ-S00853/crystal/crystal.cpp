//00853
#include<bits\stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int n;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		b[i]=i*(a[i+1]-a[i])+b[i-1];
	}
	int l=1,r=1;
	int mx=0;
	while(r<n){
		//now=b[r]-b[l]-(a[l+1]-a[l])*(r-l),add=(a[r+2]-a[r+1])*(r-l+1);
		if((b[r]-b[l-1]-(a[l+1]-a[l])*(r-l))+((a[r+2]-a[r+1])*(r-l+1))<=m) r++;
		else{
			while(l<=r&&(b[r]-b[l]-(a[l+1]-a[l])*(r-l))+((a[r+2]-a[r+1])*(r-l+1))>m){
				l++;
			}
			if(l>r){r++;l=r;}
			else r++;
		}
		mx=max(r-l+1,mx);
	}
	cout<<mx;
	return 0;
}

