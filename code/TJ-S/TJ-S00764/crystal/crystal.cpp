#include<bits/stdc++.h>
using namespace std;
long long a[500050]={},n,m,b[500050]={},c,d,e=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]<=a[i+1]){
			b[i]=a[i+1]-a[i];
		}else{
			b[i]=a[i]-a[i+1];
		}
	}
	for(int i=1;i<=n;i++){
		c=m;
		d=1;
		for(int j=i+1;j<=n;j++){
			if(c<b[j-1]){
				break;
			}
			c-=b[j-1];
			d++;
		}
		if(e<d){
			e=d;
		}
	}
	cout<<e;
	return 0;
}
