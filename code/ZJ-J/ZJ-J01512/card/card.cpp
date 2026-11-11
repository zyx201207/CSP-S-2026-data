#include<bits/stdc++.h>
using namespace std;
int a[500005],d[500005],vis[500005],q[500005],e[500005];
map<int,int>mm;
int main(){ 
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	//-------------------------------------
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int step=1,kk=1;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]==false){
				mm[a[j]]=step;
				e[step++]=a[j];
				vis[a[j]]=true;}
			else{
				for(int k=mm[a[j]];k<step;k++){
					q[kk++]=e[k];
					vis[e[k]]=false;}
				vis[a[j]]=true;
				step=mm[a[j]]+1;}}
		for(int j=1;j<kk;j++) a[i+j-1]=q[j];
		for(int j=1;j<step;j++){
			a[i+kk+j-2]=e[j];
			d[e[j]]++;
			vis[e[j]]=false;}cout<<i<<' ';
		for(int i=1;i<=m;i++) cout<<d[i]<<' ';cout<<endl;}
	for(int i=1;i<=m;i++) cout<<d[i]<<' ';
	//-------------------------------------
	//fclose(stdout);fclose(stdin);
	return 0;}