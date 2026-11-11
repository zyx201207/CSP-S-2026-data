#include<bits/stdc++.h>
using namespace std;
long long int a[50005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,i,j,k=0,s=0,l=0,c;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c=a[2]-a[1];
	for(i=2;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			k++;
			break;
		}
	}
	if(k==0){
		for(i=0;i<=m;i+=l){
			l+=c;
			s++;
		}
		cout<<s;
		return 0;
	}
	cout<<s+1;
	return 0;
} 
