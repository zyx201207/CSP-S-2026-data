#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],f[N],s[N];int aa=1,b=3,c=7,d=31,e=63;
int main(){
	freopen("and.in","r",stdin);
	freopen(and.out"","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]%2==1){
			s[i]=(s[i-1]&a[i]);
		}else{
			
		}
	}
	
	cout<<(aa&b&c&d&e);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
