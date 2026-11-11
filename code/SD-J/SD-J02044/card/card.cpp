#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long a[maxn],b[maxn],c[maxn],d[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){	
			if(c[a[j]]==0){
				b[a[j]]=j;
				c[a[j]]++;
			}		
			else if(c[a[j]]!=0){
				while(b[a[j]]<j){
					c[b[a[j]]]=0;
					b[a[j]]++;
				}
				b[a[j]]=j;
				c[a[j]]++;
			}
		}
		for(int j=1;j<=n;j++){
			if(c[a[j]]!=0){
				d[a[j]]++;
				c[a[j]]=0;
			}
		}
		for(int j=1;j<=n;j++){
			b[a[j]]=0;
			c[a[j]]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(d[a[i]]!=0){
			cout<<d[a[i]]<<" ";
			d[a[i]]=0;
		}
	}
	return 0;
} 
