#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int b[N];
int c[N];
int d[N];
int n,m;
int main(){
	freopen("card.in","r",stdin); //!!!
	freopen("card.out","w",stdout); //!!!
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int t=1;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				b[t]=a[j];
				c[a[j]]=t;
			}else{
				for(int k=c[a[j]];k<=t;k++){
					b[k]=0;
				}
				t=c[a[j]];
				b[t]=a[j];
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j]){
				d[j]++;
			}
		}
	}
//	int ans=0;
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
//	cout<<ans;
	return 0;
}