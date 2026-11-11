#include<bits/stdc++.h>
using namespace std;
int n,m,sa[200001],v[100001],mx,a;
void s_s(int x,int k,int z){
	v[x]=1;
	if(z==0){
		mx=max(k,mx);
		return ; 
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			s_s(i,k&sa[i],z-1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sa[i];
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			s_s(i,sa[i],m-1);
			v[i]=0;
		}
	}
	cout<<mx;
	return 0;
}
