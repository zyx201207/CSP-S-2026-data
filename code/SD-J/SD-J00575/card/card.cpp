#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],c[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool flag=0;
		for(int j=i,z=n;j<=n;){
			while(z>=j){
				if(a[z]==a[j]) {
					flag=1;
					c[a[z]]++;
					break;
				}
				z--;
			}
			if(!flag){
				c[z]++;
				break;
			}
			j=z+1;
			z=n;
			flag=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
