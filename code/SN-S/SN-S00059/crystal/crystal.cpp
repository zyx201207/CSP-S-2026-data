#include<bits/stdc++.h>
using namespace std;
int n,be=1,en=2,maxn=-1;
long long m,a[500005],dis[500005];
int main(){
	ifstream cin("crystal.in");
	ofstream cout("crystal.out");
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=2;i<=n;i++){
		dis[i]=dis[i-1]+a[i]-a[i-1];
	}
	long long dst=dis[en]-dis[be];
	while(en<=n){
		if(dst<=m){
			if(maxn<(en-be+1)){
				maxn=en-be+1;
			}
			en++;
			dst+=(dis[en]-dis[en-1])*(en-be);
		}else{
			be++;
			dst-=(dis[en]-dis[be-1]);	
		}
	}
	cout<<maxn;
	return 0;
}
