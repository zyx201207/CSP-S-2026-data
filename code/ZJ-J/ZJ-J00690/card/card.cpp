#include<bits/stdc++.h>
using namespace std;
int n,m,md[300007],a[500007],mp[300007];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int x,i=1;i<=n;i++){
		cin>>x;
		a[i]=x;
		mp[x]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j=mp[a[j]]+1){
			md[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<md[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}