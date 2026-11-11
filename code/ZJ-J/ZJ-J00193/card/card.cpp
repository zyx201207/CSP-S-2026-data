#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005],b[5005],book[5005],ans[5005],flag[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int k=0;			
		for(int j=i;j<=n;j++){
			if(book[a[j]]){
				for(int r=book[a[j]]+1;r<=k;r++){
					book[b[r]]=b[r]=0;
				}				
				k=book[a[j]]-1;
			}	
			b[++k]=a[j];
			book[a[j]]=k;
		}
		memset(flag,0,sizeof(flag));
		for(int j=1;j<=k;j++){
			if(!flag[b[j]]){
				ans[b[j]]++;
				flag[b[j]]=1;
			}
		}
		memset(b,0,sizeof(b));
		memset(book,0,sizeof(book));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
