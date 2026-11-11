#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],b[200005],x,c,y=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		x=0;
		for(int j=1;j<=n;j++){
			if(a[j]>x){
				x=a[j];
				c=j;
			}
		}
		b[i]=x;
		a[c]=0;
	}
	for(int i=2;i<=m;i++){
		y=b[i-1]&b[i];
	}
	cout<<y;
	return 0;
}