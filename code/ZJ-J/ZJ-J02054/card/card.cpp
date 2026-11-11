#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;

int n,m;
int a[MAXN],b[MAXN];


int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int x=0;x<MAXN;x++){
			b[x]=0;
		}
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int x=i;x<j;x++){
				if(b[x]=b[j]){
					for(int y=x+1;y<=j;y++) b[y]==0;
				}
			}
		}
		int ans=0;
		for(int j=i;j<=MAXN;j++){
			cout<<b[j];
			if(b[j]==i) ans++;
			if(b[j]==0){
				cout<<ans<<' ';
				break;
			}
		}
	}
	
	return 0;
}
