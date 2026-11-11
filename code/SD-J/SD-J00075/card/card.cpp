#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,m,b[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		int r=0,x;
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			for(x=1;x<=r;x++){
				if(b[x]==a[j])break;
			}
			if(b[x]==a[j]){
				r=x;
			}else{
				b[++r]=a[j];
			}
		}
		for(int j=1;j<=r;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
