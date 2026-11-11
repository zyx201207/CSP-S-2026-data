#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
int a[n+1],sum[m+1],pd[m+1];
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=m;i++){
	sum[i]=0;
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		pd[j]=0;
	}
	for(int j=i;j<=n;j++){
		if(pd[a[j]]!=0){
			for(int z=pd[a[j]];z<j;z++){
				pd[a[z]]=0;
			}
		}
			pd[a[j]]=j;
	}
	for(int j=1;j<=m;j++){
		if(pd[j]!=0){
			sum[j]++;
		}
	}
}
for(int i=1;i<=m;i++){
	cout<<sum[i]<<" ";
}
return 0;
}

