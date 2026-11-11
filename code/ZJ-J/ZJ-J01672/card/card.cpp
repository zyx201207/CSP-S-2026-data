#include<bits/stdc++.h>
using namespace std;
int n,m,a[300010],ans[300010],s,jl[300010];
bool book[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(book,0,sizeof book);
			s=0;
			for(int k=i;k<=n;k++){
				if(book[a[k]]==1){
					while(jl[s]!=a[k]&&s>0){
						ans[jl[s]]--;
						s--;
					}
				}
				else{
					s++;
					jl[s]=a[k];
					ans[a[k]]++;
					book[a[k]]=1;
				}
			}
		}	
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(book[a[i]]==1){
			for(int j=s;j>=1;j--){
				if(jl[j]==a[i])break;
				s--;
				ans[jl[j]]=ans[jl[j]]-i;
			}
		}else{
			s++;
			jl[s]=a[i];
			ans[a[i]]+=i;
			book[a[i]]=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}