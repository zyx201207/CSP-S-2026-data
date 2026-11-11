#include<bits/stdc++.h>
using namespace std;
long long a[1000005],maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
	}
	if(m==2){
		maxx=-1;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}
	if(m==3){
		maxx=-1;
		for(int x=1;x<=n;x++){
			for(int i=x;i<=n;i++){
				for(int j=i;j<=n;j++){
					maxx=max(maxx,(a[i]&a[j]&a[x]));
				}
			}
		}
		cout<<maxx;
	}
	
} 
