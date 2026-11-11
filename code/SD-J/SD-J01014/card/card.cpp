#include<bits/stdc++.h>
using namespace std;
int a[5001],b[3001],n,m;
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int a1[n+1]={0},b1[m+1]={0};
		for(int j=i;j<=n;j++){
			a1[j]=a[j];
			if(!b1[a[j]])
			b1[a[j]]=1;
			else{
				a1[j]=0;
				int z=j-1;
				while(a1[z]!=a[j]){
					a1[z]=0;
					b1[a1[z]]=0;
					z--;
				}
			}
		}
		for(int e=i;e<=n;e++){
			b[a1[e]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
}
