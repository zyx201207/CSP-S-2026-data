#include<bits/stdc++.h>
using namespace std;
long long a[200001],x=0,m;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(long long i=1;i<=m;i++){
		cin>>a[i]>>c[i];
	}
	for(long long i=1;i<=m;i++){
		if(c[i]==c[m]){
			if(a[i]>a[m]){
				a[i]-=a[m];
				a[m]=0;
			}
			else{
				a[m]-=a[i];
				a[i]=0;
			}
		}
		else{
			if(a[i]>a[m]){
				x+=a[m];
				a[i]-=a[m];
				a[m]=0;
			}
			else{
				x+=a[i];
				a[m]-=a[i];
				a[i]=0;
			}
		}
		if(a[m]==0){
			m--;
		}
		if(a[i]!=0){
			i--;
		}
	}
	cout<<x;
	return 0;
}