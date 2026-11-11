#include<bits/stdc++.h> 
using namespace std;
long long a[600000],b[600000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,h=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool c=0;
		for(int j=2;j<=n;j++){
			if(a[j-1]>a[j]){
				swap(a[j-1],a[j]);
				c=1;
			}
		}
		if(c==0){
			break;
		}
	}
	bool p=1;
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(b[i]!=b[i-1]&&i>1){
			p=0;
		}	
	}
	if(p==1){
		long long sum=0;
		int c=0;
		while(sum<=m&&c+1<=n){
			sum+=c*b[1+c];
			c++;
		}
		h=max(h,c-1);
		if(h==0){
			cout<<1;
			return 0;
		}
		cout<<h;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long sum=0;
		int c=0;
		while(sum<=m&&c+i<=n){
			sum+=c*b[i+c];
			c++;
		}
		h=max(h,c-1);
	}
	if(h==0){
		cout<<1;
		return 0;
	}
	cout<<h;
	return 0;
}