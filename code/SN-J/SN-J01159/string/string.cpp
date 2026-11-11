#include<bits/stdc++.h>
using namespace std;
long long x[200005];
char y[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long s=0,a=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		s+=x[i];
	}
	s/=2;
	long long z;
	int l=0,r=n-1;
	while(s){
		z=min(x[l],x[r]);
		if(s>z){
			s-=z;
		}else{
			z=s;
			s=0;
		}
		x[l]-=z;
		x[r]-=z;
		if(y[r]!=y[l]){
			a+=z;
		}
		if(x[l]==0){
			l++;
		}
		if(x[r]==0){
			r--;
		}
	}
	cout<<a;
	return 0;
}
