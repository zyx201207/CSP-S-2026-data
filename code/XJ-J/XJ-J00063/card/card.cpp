#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500055];
int next_char[300055];
int next[500055];
int next_string[500055];
int cnt[500055];
int ans[300055];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
	cnt[i]=0;
	next_char[i]=-1;
	if(i<=m)ans[i]=0;
}
for(int i=n;i>=1;i--){
	next[i]=next_char[a[i]];
	if(next[i])next_char[a[i]]=i;
}
int nxt=n+1;
for(int i=n;i>=1;i--){
	next_string[i]=nxt;
	if(next[i]!=-1)nxt=i;
}
for(int i=1;i<=n;i++){
	int x=i;
	while(x<=n){
		if(next[x]!=-1){
			x=next[x];
		}
		else{
			cnt[x]++;
			cnt[next_string[x]]--;
			x=next_string[x];
		}
	}
}
for(int i=1;i<=n;i++){
	cnt[i]+=cnt[i-1];
	ans[a[i]]+=cnt[i];
}
for(int i=1;i<=m;i++){
	cout<<ans[i]<<" ";
}
return 0;
} 
