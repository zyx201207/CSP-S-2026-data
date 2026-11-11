#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],b[100010],s[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int qqq=1;qqq<=n;qqq++){
		long long x=1,p=-1,nn=n;
		for(int k=qqq;k<=n;k++){
			b[x]=a[k];
			for(int i=1;i<x;i++){
				if(b[i]==b[x]){
					p=i;
					break;
				}
			}
			if(p!=-1){
				for(int i=1;i<=x-p;i++){
					for(int j=p;j<=x;j++){
						b[j]=b[j+1];
					}
				}
				nn-=x-p;
			}
			x++;
		}
		for(int i=1;i<=nn;i++){
			s[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}