#include<bits/stdc++.h>
using namespace std;
int a[(int)5e5+5],ans[(int)5e5+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		bool b[m+5]={0};
		for(int j=i;j<=n;j++){
			if(!b[a[j]]) b[a[j]]=true;
			else{
				for(int k=1;k<=m;k++) b[k]=0;
				b[a[j]]=1;}}
		for(int j=1;j<=m;j++) if(b[j]) ans[j]++;}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;}
