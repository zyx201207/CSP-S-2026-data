#include<bits/stdc++.h>
using namespace std;
int v[300005],a[500005],mm[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		memset(v,-1,sizeof v);
		l=i;
		for(int j=i;j<n;j++){
			if(v[a[j]]!=-1){
				memset(v,-1,j*4);
				v[a[j]]=j;
				l=j;
			}else v[a[j]]=j;
		}for(int j=l;j<n;j++)mm[a[j]]++;
	}for(int i=1;i<=m;i++)cout<<mm[i]<<" ";
}
