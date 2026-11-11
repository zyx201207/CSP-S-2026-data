#include<bits/stdc++.h>
using namespace std;
const int N=1e5*5;
int a[N+10];
int b[N+10];
int d[N+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		d[i]=0;
	}
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=i;j<=n;j++){
			x++;
			if(j==i){
				b[x]=a[j];
				continue;
			}
			else{
				int c;
				bool f=false;
				for(c=x-1;c>=1;c--){
					if(b[c]==a[j]){
						f=true;
						break;
					}
				}
				if(f==true){
					for(int k=c;k<x;k++){
						b[k]=0;
					}
					x=c;
					b[x]=a[j];
					continue;
				}
				else{
					b[x]=a[j];
				}
			}
		}
		for(int y=1;y<=x;y++){
			d[b[y]]=d[b[y]]+1;
			b[y]=0;
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	
	return 0;
}
