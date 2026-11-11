#include<bits/stdc++.h> 
using namespace std;
long long n,m,car[600007],nex[600007],b[400007],ans[400007];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>car[i];
	}
	for(int i=1;i<=m;i++)b[i]=-1e9;
	for(int i=n;i>=1;i--){
		nex[i]=b[car[i]];
		b[car[i]]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(nex[j]==-1e9)ans[car[j]]++;
			else j=nex[j]-1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

