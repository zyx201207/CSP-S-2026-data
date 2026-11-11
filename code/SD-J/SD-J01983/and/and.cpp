#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],zdz=INT_MIN,zzdz=INT_MIN,pp;
int ct[500001],ctt[500001],op[500001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		zdz=max(zdz,a[i]);
		if(i==1)pp=a[1];
		else pp=(pp&a[i]);
	}
	if(m==1){
		cout<<zdz;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				zzdz=max(zzdz,(a[i]&a[j]));
			}
		}
		cout<<zzdz;
		return 0;
	}
	if(m==n){
		cout<<pp;
		return 0;
	}
	cout<<zdz;
	return 0;
}
