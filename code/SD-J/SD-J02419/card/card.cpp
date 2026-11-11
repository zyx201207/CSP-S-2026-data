#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],t[100010],r[200010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int k=0;
		memset(r,0,sizeof(r));
		for(int j=i;j<=n;j++){
			bool b=1;
			for(int c=j-1;c>=i;c--)
				if(r[c]==a[j]){
					while(k!=c){
						r[k--]=0;
					}
					b=0;
					break;
				}
			if(b){
				r[++k]=a[j];
			}
		}
		for(int j=1;j<=k;j++){
			t[r[j]]++; 
		}
	}
	for(int i=1;i<=m;i++)
		cout<<t[i]<<" ";
	return 0;
}

