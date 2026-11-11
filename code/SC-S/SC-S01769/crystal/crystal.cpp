#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n;
long long m;
long long ans=0;
int nm[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long x_=0; int ma=-9999999,mi=99999999;
	for(int i=1;i<=n;i++){
		cin>>nm[i];
		if(nm[i]>ma) ma=nm[i];
		if(nm[i]<mi) mi=nm[i];
		x_+=nm[i];
	}
	sort(nm+1,nm+n+1); 
	x_/=n;
	x_+=1;
	int aa=1;
	while(nm[aa]<x_){
		aa++;
	}
	aa--;
	ans++;
	int le=aa-1,mm=m; 
	while(mm>0){
		mm-=(nm[aa]-nm[le]);
		if(mm>=0) ans++;
		else break;
		le--;
	}
	cout<<ans;
	return 0;
}