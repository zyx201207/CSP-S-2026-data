#include<bits/stdc++.h>
using namespace std;

int b[1010],c[200010][110],f[200010],m,n,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ma=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		ma=max(ma,a);
		int p=0;
		while(a>0){
			p++;
			b[p]=a%2;
			a/=2;	
		}
		for(int j=1;j<=p;j++){
			c[i][j]=b[p-j+1];
		}
	}
	cout << ma;
	
	return 0;
}