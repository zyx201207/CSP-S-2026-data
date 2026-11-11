#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],z[n+1],b[m+2]={0};
	for(int i=1;i<=n;i++){
		cin>>a[n]; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			z[j]=a[j];
			b[a[j]]++;
			if(b[a[j]]>1){
				b[a[j]]=0;
			}
	}
	for(int i=1;i<=n;i++){
		if(b[i]>0){
			cout<<z[i]<" ";
		}
	}
	return 0;
}
}
