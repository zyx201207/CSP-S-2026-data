#include<bits/stdc++.h>
using namespace std;
int n,b[214514][30],f[214514],m,k,uf,s1,s2,l,ip;
long long d,a;
int c[214514],s[30];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>f[i];
		c[i]=1;
		if(!(f[i]+1-i)){
			l=1;
		}
	}
	sort(f,f+n,greater<int>());
	if(m==1){
		cout<<f[0];
	}else if(! l){
		ip=1;
		while(m-1){
			ip++;
			m/=2;
		}
		m=1;
		while(ip--){
			m*=2;
		}
		cout<<n-1-m;
	}else{
		cout<<f[m-1];
	}
}
