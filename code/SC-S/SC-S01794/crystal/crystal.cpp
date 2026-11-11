#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[100000],s=0,b[100000],c[10000];
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=1;j<=m;j++){
			if(a[i]>=0||abs(a[i])<=j){
				b[a[i]+j]++;
				s=max(s,b[a[i]+j]);
			}
			else {
				c[abs(a[i])-j]++;
				s=max(s,c[abs(a[i])-j]);
			}
		}
	}
	cout<<s<<endl;
	return 0;
}