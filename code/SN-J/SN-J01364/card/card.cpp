#include<bits/stdc++.h>
using namespace std;
long long n,m,l=1;
int a[500005];
int b[500005];
int ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		l=1;
		for(int j=i;j<=n;j++){
			int it=-1;
			for(int k=1;k<=l;k++){
				if(b[k]==a[j]){
					it=k;
					break;
				}
			}
			if(it!=-1){
				l=it+1;
			}else{
				b[l]=a[j];
				l++;
			}
		}
		for(int j=1;j<l;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
} 
