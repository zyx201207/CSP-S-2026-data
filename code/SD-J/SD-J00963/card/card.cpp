#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],c[N],tong[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tong[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		if(tong[a[i]]!=1){
			b[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		int top=i;
		for(int j=i;j<=n;j++){
			if(tong[a[j]]==1&&b[a[j]]==0){
				c[top++]=a[j];
			}	
			else if(tong[a[j]]!=1&&b[a[j]]==1){
				b[a[j]]--;
				top=j;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<1;
	}
	return 0; 
}
