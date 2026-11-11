#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],b[500050],ans[500050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	
	for(int i=1+1;i<=n;i++){
		memset(b,0,sizeof b);
		int l=1,r=1;
		for(int j=i+1;j<=n;j++){
			for(int k=l;k<=r-1;k++){
				if(a[j]==a[k]){
					r=k;
					break;
				}
			}
			b[r]=a[j];
			r++;
		}
		for(int j=l;j<=r;j++){
			if(b[j]==i){
				ans[i]++;
			}
		}
	}
	for(int i=2;i<=n;i++){
		cout<<0<<" ";
	}
	return 0;
}

