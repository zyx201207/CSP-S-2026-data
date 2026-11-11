#include<bits/stdc++.h>
using namespace std;
int n,m,aaa;
int a[100010]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			aaa=a[i];
			a[i]=a[i-1];
			a[i-1]=aaa;
		}
	}
	int b,c;
	for(int i=1;i<=n;i++){
		b=0,c=0;
		if(i>=2){
			for(int j=1;j<i;j++){
				b=a[i]-a[j];
				c+=b; 
			}
		}
		if(c==m and a[i]!=a[i+1]){
			cout<<i;
			break;
		}
	}
	return 0;
}
