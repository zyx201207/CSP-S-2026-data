#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],c[500005],t=0,x[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int t=0;
		for(int j=0;j<n;j++){
			b[j]=0;
			c[j]=0;
		}
		for(int j=i;j<n;j++){
			if(c[a[j]]==1){
				for(int z=t-1;z>=0;z--){
					if(a[j]==b[z]){
						break;
					}
					c[b[z]]=0;
					b[z]=0;
					t--;
					
			 	}
				t--;
			}
			else{
				c[a[j]]=1;
				b[t]=a[j];
			}
			t++;
		}
		for(int j=0;j<=t;j++){
			x[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<x[i]<<" ";
	}
	return 0;
} 
