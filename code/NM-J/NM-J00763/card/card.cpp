#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int a[200005];
	int n,m;
    cin>>n>>m;
    int cc[m+5]={};
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[200005]={};
		int c=1;
		for(int j=i;j<=n;j++){
			int x=0;
			bool f=1;
			for(int k=1;k<=c;k++){
				if(b[k] == a[j]){
					f=0;
					x=k;
					break;
				}
				if(b[k]==0){
					break;
				}
			}
			if(f){
				b[c] = a[j];
				c++;
			}
			else if(f==0){
				for(int k=x;k<c;k++){
					b[k]=0;
				}
				b[x]=a[j];
				c=x+1;
			}
		}
				for(int j=1;j<=c;j++){
					cc[b[j]] ++;
				}
	}
	for(int i=1;i<=m;i++){
		cout<<cc[i]<<" ";
	}
	return 0;
}
