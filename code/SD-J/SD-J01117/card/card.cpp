#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],cnt[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		cout<<n;
	}
	else{
		for(int i=1;i<=m;i++){
			cout<<i<<" ";
		}	
	}
	return 0;
}
