#include<bits/stdc++.h>
using namespace std;
int n,m,a[5*100005],b[3*100005],d[3*100005],q[5*100005],k=1;
bool c[3*100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(c,false,sizeof(c));
		k=1;
		for(int j=i;j<=n;j++){
			q[k]=a[j];
			if(c[a[j]]==true){
				while(1){
					c[q[k-1]]=false;
					if(q[k-1]==a[j]){
						k--;
						break;
					}
					k--;
				}
			}
			else c[a[j]]=true;
			k++;
		}
		for(int j=i;j<=n;j++){
			if(c[a[j]])d[a[j]]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<d[j]<<" ";
	}
	return 0;
}
