#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],c[N],b[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b[j]=0;
		}
		for(int j=1;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
			}else if(b[a[j]]==1){
				for(int k=1;k<=j;k++){
					if(b[a[k]]==b[a[j]]){
						b[a[k]]=0;
						num=1;
					}if(num==1){
						b[a[k]]=0;
					}
				}
				b[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]==1){
				c[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

