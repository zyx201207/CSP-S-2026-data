#include<bits/stdc++.h>
using namespace std;
int a[20005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];}
	sort(a+1,a+n+1);
	
	for(int i=2;i<=n;i++){
		int al=0;
		if(a[i]==a[i+1]) continue;
		for(int j=1;j<i;j++){
			int c=a[i]-a[j];
			al=c+al;
		}
		if(al>m){
			cout<<i-1;
			return 0;
		}
	}
	
	return 0;
}