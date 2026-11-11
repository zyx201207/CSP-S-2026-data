#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],t[300010],ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j<=n;j++){
			int s=lower_bound(b+1,b+x+1,a[j])-b;
			if(b[s]!=a[j]){
				b[x+1]=a[j];
				x++;
			}else{
				x=s-1;
			}
		}
		for(int j=1;j<=m;j++){
			int s=lower_bound(b+1,b+x+1,a[j])-b;
			if(b[s]==a[j]){
				t[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
