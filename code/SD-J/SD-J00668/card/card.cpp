#include<bits/stdc++.h>
using namespace std;
int a[500010];
long long ans[300010];
struct p{
	int id;
	bool cx;
}check[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int head=1,tail=1,pai[500010]={0,a[i]};
		check[a[i]].cx=1;
		check[a[i]].id=1;
		for(int j=i+1;j<=n;++j){	
			if(check[a[j]].cx){
				for(int k=check[a[j]].id+1;k<=tail;++k){
					check[pai[k]].cx=0;
					check[pai[k]].id=0;
				}
				tail=check[a[j]].id;
			}else{
				tail++;
				pai[tail]=a[j];
				check[a[j]].cx=1;
				check[a[j]].id=tail;
			}
		}
		for(int j=head;j<=tail;++j){
			ans[pai[j]]++;
			check[pai[j]].cx=0;
			check[pai[j]].id=0;
		}
	}	
	for(int i=1;i<=m;++i)
		cout<<ans[i]<<' ';
}
