#include <iostream>
using namespace std;
int n,m,b=1,x;
int a[500100],z[300100],c[300100];
int main(){
	freopen("card.in","r",stdin)
	freopen("card.out","w",stdout)
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b=i;
		for(int j=1;j<=n-i+1-x;j++){
			z[j]=a[b];
			for(int k=1;k<j-x;k++){
				if(z[k]==z[j-x]){
					x+=k;
					j-=k+1;
				}
			}
			b++;
		}
		for(int y=1;y<=n-i+1-x;y++){
			c[z[y]]++;
		}
		x=0;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';
	}
	return 0;
}
