#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
int a[500050],c[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    int b[300050];
	    for(int j=1;j<=300000;j++){
	    	b[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
			}
			else{
				for(int k=j;k>=1;k--){
					if(a[k]==a[j]){
						break;
					}
					b[a[k]]=0;
				}
			}
	    }
		for(int j=1;j<=m;j++){
			if(b[j]!=0) c[j]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
