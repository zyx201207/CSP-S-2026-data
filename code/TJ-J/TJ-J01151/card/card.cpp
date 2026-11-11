#include<bits/stdc++.h>
using namespace std;
long long a[1000005],b[300005];
bool ok[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ok[j]=0;
		}
		for(int j=i;j<=n;j++){
			for(int x=i;x<j;x++){
				if(a[x]==a[j]){
					for(int y=x;y<j;y++) ok[y]=1;
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(!ok[j]) b[a[j]]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<b[j]<<" ";
	}
} 
