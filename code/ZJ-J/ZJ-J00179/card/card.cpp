#include<bits/stdc++.h>
using namespace std;
int n,m,a[500100],cnt[300100];
bool cmp[300100];
stack<int> s[500100];
void slove(int l){
	memset(cmp,0,sizeof(cmp));
	for(int i=l;i<=n;i++){
		if(cmp[a[i]]==1){
			while(s[l].top()!=a[i]){
				cmp[s[l].top()]=0;
				s[l].pop();
			}
		}
		else{
			s[l].push(a[i]);
			cmp[a[i]]=1;
		}
	}
	while(!s[l].empty()){
		cnt[s[l].top()]++;
		s[l].pop();
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) slove(i);
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}