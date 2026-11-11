#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x,p=1;
	int a[1000];
	int b[1000];
	int c[1000];
	int d[1000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			int x=a[i];	
			c[i]=a[i];	
			b[x]++;
			if(b[x]==2){
				break;
			}
		}
		for(int g=1;g<=n;g++){
			if(c[g]==p){
				d[j]++;
			}
		}	
	}
	cout<<d;
}
