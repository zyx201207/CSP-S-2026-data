#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],s[N],f[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		
		if(s[a[i]]==0) s[a[i]]=i;
		else{
			f[i]=s[a[i]];
			s[a[i]]=i;
		}
		//cout<<s[a[i]];
	}
	//for(int i=1;i<=n;i++) cout<<f[i]<<' ';
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(f[j]!=0){
				j=f[j];
			}
			c[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",c[i]);
	return 0;
}