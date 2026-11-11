#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],b[M],ans[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=0;
		}
	}
	if(f){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				ans[a[i]]=i;
			}
		}for(int i=1;i<m;i++){
			cout<<ans[i]<<" ";
		}cout<<ans[m];
		return 0;
	}if(m==1){
		cout<<n;
		return 0;
	}if(m==2){
		if(a[n]==1){
			ans[1]=n;
			for(int i=1;i<=n;i++){
				if(a[i]==2)ans[2]++;
			}
		}else{
			ans[2]=n;
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans[1]++;
			}
		}for(int i=1;i<m;i++){
			cout<<ans[i]<<" ";
		}cout<<ans[m];
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(b[a[i]]==0){
			b[a[i]]=i;
		}
	}
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(b[a[i]]==i){
				ans[a[i]]++;
			}else{
				i=b[a[i]]-1;
			}
		}
	}for(int i=1;i<m;i++){
		cout<<ans[i]<<" ";
	}cout<<ans[m];
	return 0;
}
