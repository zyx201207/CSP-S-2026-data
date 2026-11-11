#include<bits/stdc++.h>
using namespace std;
int n,b[214514],f[514514],m,k;
long long d,a;
int c[214514];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		b[f[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			c[f[i]]++;
			if(b[f[j]]>i&&f[i]!=f[j]){
				break;
			}
		}
	}
	c[f[1]]++;
	for(int i=1;i<=m;i++){
		if(b[i]==n){
			cout<<n<<" ";
		}else{
			cout<<c[i]<<" ";
		}
	}
}
