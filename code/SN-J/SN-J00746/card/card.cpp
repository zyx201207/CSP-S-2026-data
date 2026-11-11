//SN-J00746 张宸熙 西安市第十二中学 
#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int n,m,a[N],b[N],c[N],f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			f=1;
		}
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[j]=a[j];
			for(int k=1;k<=j;k++){
				if(c[k]==a[j]&&k!=j){
					for(int g=k;g<j;g++){
						c[g]=0;
					}
					break;
				}
			}
		} 
		for(int j=i;j<=n;j++){
			if(c[j]!=0){
				b[c[j]]++;
				c[j]=0;
			}
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
