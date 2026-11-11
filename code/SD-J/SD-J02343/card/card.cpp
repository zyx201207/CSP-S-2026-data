#include<bits/stdc++.h>
using namespace std;
int n,m,sa[500005],sb[300005],sd[300005];
void s_s(){
	for(int i=1;i<=m;i++){
		sb[i]=0;
	}
}
void dfs(int x){
	s_s();
	for(int i=x;i<=n;i++){
		sb[sa[i]]++;
		if(sb[sa[i]]%2==0){
			s_s();
			sb[sa[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		sd[i]+=sb[i];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sa[i];
	}
	for(int i=1;i<=n;i++){
		dfs(i);
	}
	for(int i=1;i<=m;i++){
		cout<<sd[i]<<" ";
	}
	return 0;
} 
