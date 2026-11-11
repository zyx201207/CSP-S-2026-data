#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
int a[500010];
int b[500010];
int x=0;
int flag1=0;
int flag2=0;
int c[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		x=max(x,b[a[i]]);
		if(a[i]!=i) flag1=1;
		if(i>=3 && a[i]-a[i-1]!=a[i-1]-a[i-2]) flag2=0;
	}
	if(m==0){
		cout<<x;
		return 0;
	}
	x=0; 
	if(flag1==0){
		for(int i=1;i<=n-1;i++){
			c[i]=(1+i)*i/2;
			if(m<c[i]){
				cout<<x+1;
				return 0;
			}
			x=i;
		}
		cout<<x+1;
		return 0;
	}
	x=0;
	if(flag2==0) {
		int y=a[2]-a[1];
		for(int i=1;i<=n-1;i++){
			c[i]=i*(i+1)*y/2;
			if(m<c[i]){
				cout<<x+1;
				return 0;
			}
			x=i;
		}
		cout<<x+1;
		return 0;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}