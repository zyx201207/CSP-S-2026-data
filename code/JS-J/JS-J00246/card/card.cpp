#include <bits/stdc++.h>
using namespace std;
long long n,m,a[555555],b[555555],x,y,c[333333];
bool f=true;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	for(int i=1;i<=n;i++){
		x=1;
		for(int j=i;j<=n;j++){
			f=true;
			if(x>2){
				for(int k=1;k<x;k++){
					if(b[k]==a[j]){
						y=k;f=false;break;
						}
					}
					if(f==false){for(int k=y+1;k<x;k++){
					b[k]=0;
					}
				x=y+1;}
				}
				else{b[x]=a[j];x++;continue;}
			}
			for(int j=1;j<x;j++){
				c[b[j]]++;
				}
		}
		for(int i=1;i<=m;i++){
			cout<<c[i]<<" ";
			}
    return 0;
}
