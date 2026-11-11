#include<bits/stdc++.h>
using namespace std;
int a[500050],b[500050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	deque<int> aa;
	int a2[500050];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)a2[i]=a[i];
		for(int j=i;j<=n;j++){
			int yy=j; 
			for(int k=yy;k<=n;k++){
				if(a2[k]==a2[yy]){
					for(int kk=yy;kk<=k;kk++)if(kk!=k)a2[kk]=0;
					yy=k;
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(a2[j]==0)continue;
			b[a2[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
