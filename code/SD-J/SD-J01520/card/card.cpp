#include<bits/stdc++.h>
using namespace std;
int a[500004],js[300004],b[500003],l[300005],k=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--){
		k++;
		b[k]=a[i];
		if(l[a[i]]==0){
			l[a[i]]=k;
		}
		else{
			for(int j=k-1;j>l[a[i]];j--){
				l[b[j]]=0;
				b[j]=0;
			}
			k=l[a[i]];
		}
		for(int j=1;j<=k;j++){
			js[b[j]]++;
		}
	
	}
	for(int i=1;i<=m;i++)
		cout<<js[i]<<' ';
}
