#include<bits/stdc++.h>
using namespace std;
int a[500555],table[500555],cur,ans[500555];
int n,m;
int found(int x){
	int s=1;
	while(table[s]!=0){
		if(table[s]==x){
			return s;
		}
		s++;
	}
	return 0;
}
void clear(int x){
	while(table[x]!=0){
		table[x]=0;
		x++;
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
		cur=1;
		for(int j=i;j<=n;j++){
			int w=found(a[j]);
			if(w){
				clear(w);
				cur=w;
				table[cur]=a[j];
				cur++;
			}else{
				table[cur]=a[j];
				cur++;
			}
		}
		for(int j=1;j<=cur;j++){
			ans[table[j]]++;
			table[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

