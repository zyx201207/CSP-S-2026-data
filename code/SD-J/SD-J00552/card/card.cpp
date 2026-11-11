#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			for(int k=1;k<=n;k++){
				if(b[k]==a[j]){
					for(int w=k;w<=n;w++) b[k]=-1;
				}
			}
			b[j]=a[j];
		}
		for(int k=1;k<=n;k++){
			if(b[k]==i) c[i]++;
		}
		for(int k=1;k<=n;k++){
			b[k]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
