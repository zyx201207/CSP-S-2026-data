#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],s;
int t[300005];
int b[300005];
int x[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=i;j<=n;j++){
			if(x[a[j]]==0){
				b[++s]=a[j];
				x[a[j]]=1;
			}
			else{
				for(int l=s;l>=1;l--){
					if(b[l]==a[j]){
						s=l;
						break;
					}
					x[b[l]]=0;
				}
			}
		}
		for(int l=1;l<=s;l++){
			t[b[l]]++;
		}
		memset(b,0,sizeof(b));
		memset(x,0,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
