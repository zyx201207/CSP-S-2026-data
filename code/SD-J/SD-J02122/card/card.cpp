#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int a[500005];
bool b[500005];
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for (int j=i;j<=n;j++){
			if (b[a[j]]==1){
				for (int k=j-1;k>=1;k--){
					if (a[k]==a[j]){
						break;
					}
					else{
						b[a[k]]=0;
					}
				}
			}
			else{
				b[a[j]]=1;
			}
		}
		for (int j=1;j<=m;j++){
			if (b[j]){
				c[j]++;
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
