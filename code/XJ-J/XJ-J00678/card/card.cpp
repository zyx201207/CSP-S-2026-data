#include<bits/stdc++.h>
using namespace std;
long long n,m,ii,na;
long long tong[1000100];
long long p[1000010];
int a[1000010];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	na=n;
	for(int r=1;r<=n;r++){
		memset(a,0,sizeof(a));
		for(int i=r;i<=n;i++){
			a[i]=p[i];
			for(int j=1;j<i;j++){
				if(a[i]==a[j]){
					for(int z=j;z<i;z++){
						a[z]=0;
					}
				}
			}
		}
		for(int i=1;i<=na;i++){
			if(a[i]!=0){
				tong[a[i]]++;
			}
		} 
    }
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
	

}