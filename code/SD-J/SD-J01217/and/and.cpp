#include<bits/stdc++.h>
using namespace std;
long long n,m; 
long long h[200005];
long long a[200005];
int w=1,maxx;
long long x(long long x1,long long x2){
	string num="";
	long long numm=0,ii=0;
	while(x1>0 && x2>0){
		num+=(((x1%2)==(x2%2))+'0');
		ii+=1;
		x1/=2;
		x2/=2;
	}
	for(ii;ii>0;ii--){
		numm=numm*2+(num[ii-1]-'0');
	}
	return numm;
}
long long ans(){
	long long s=a[n];
	for(int i=1;i<m;i++){
		s=x(s,a[n-i]);
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		h[x]++;
		maxx=max(maxx,x);
	}
	for(int i=1;i<=maxx;i++){
		for(int j=1;j<=h[i];j++){
			a[w]=i;
			w++;
		}
	}
	cout<<ans();
	return 0; 
}

