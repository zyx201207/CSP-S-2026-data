#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5000+10;
int c[N];
int a[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int d[N]{0};
		for(int j=i;j<=n;j++){
			if(d[a[j]]==0){
				d[a[j]]=1;
			}
			else{
				for(int k=0;k<=5009;k++){
					d[k]=0;
				}
				d[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(d[a[j]]!=0){
				c[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
