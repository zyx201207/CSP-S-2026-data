#include<bits/stdc++.h>
#define N 200005
using namespace std;
int n,m,a[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
	}else if(m==2){
		int res=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[n]){
				res++;
			}
		}
		cout<<res<<' '<<n;
	}else{
		for(int i=n;i>=1;i--){
			if(ans[a[i]]==0){
				ans[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
