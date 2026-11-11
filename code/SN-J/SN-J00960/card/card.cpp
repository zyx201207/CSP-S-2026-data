#include <bits/stdc++.h>
using namespace std;
int tong[300005],t[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	for(int p=1;p<=n;p++){
		int a[500005]={0};
		l=1;
		for(int i=p;i<=n;i++){
			for(int j=1;j<=l;j++){
				if(a[j]==t[i]){
					for(int k=j;k<=n;k++){
						a[k]=0;
					}
					l=j;
					a[j]=t[i];
				}else{
					a[++l]=t[i];
					
				}
			}
		}
		for(int j=0;j<=l;j++){
			tong[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}
