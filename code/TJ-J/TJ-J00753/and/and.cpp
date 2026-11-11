#include<bits/stdc++.h> 
using namespace std;
int s(int a,int b){
	int x[100005];
	int y[100005];
	int z;
	for(int i=0;a!=0;i++){
		x[i]=a%2;
		a=a/2+x[i];
		y[i]=a%2;
		b=b/2+y[i];
	}
	for(int i=0;a!=0;i++){
		if(x[i]==y[i]&&x[i]==1){
			int g=1;
			for(int j=0;j<=i;j++){
				g*=2;
			}
			z+=g;
		}
	}
	return z;
}
int main(){
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	int n,m,a[200005],ans=0,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]=a[j]){
				for(k=j;k<=n;k++){
					a[j]=a[j+1];
				}
			}
		}
	}
	int o=1;
	for(int i=0;i<k;i++){
		for(int j=i;j<m+i;j++){
			o=s(o,a[i]);
			if(o>ans){
				ans=o;
			}
		}
	}
	cout<<ans;
	return 0;
}
