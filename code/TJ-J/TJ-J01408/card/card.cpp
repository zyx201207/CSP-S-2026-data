#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],stackn[500005],top;
long long ans[300005];
void work(int k){
	top=0;
	memset(b,0,sizeof(b));
	for(int i=k;i<=n;i++){
		if(!b[a[i]]){
			stackn[top++]=a[i];
			b[a[i]]++;
		}else{
			while(b[a[i]]){
				int v=stackn[--top];
				b[v]--;
			}
			stackn[top++]=a[i];
			b[a[i]]++;
		}
	}
	for(int i=0;i<top;i++){
		ans[stackn[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		work(i);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
