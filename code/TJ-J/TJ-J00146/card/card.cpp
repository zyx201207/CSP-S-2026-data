#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int j=1;j<=n;j++){
		int pp=1;
		int c[200005]={0};
		
		for(int i=j;i<=n;i++){
			
			if(c[a[i]]!=0){
				pp=c[a[i]];
				
				c[a[i]]=i;
			}
			else{
				c[a[i]]=i;
			}
			pp++;
		}
		for(int i=j;i<=pp;i++){
			b[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[a[i]]<<" ";
	}
	return 0;
} 
