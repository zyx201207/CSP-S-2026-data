//card
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int N=5e5+10,M=3e5+10;
ll a[N];
ll now_cards[M],tot=0;
ll cards_pos[M];
ll ans[M];
ll n,m;

void init(){
	fill(now_cards,now_cards+N,0);
	fill(cards_pos,cards_pos+M,0);
}

void solveA(){
	for(int i=1;i<=n;i++) cout<<n-i+1<<' ';
	return;
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=0;
	}
	
	if(flag){
		solveA();
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		init();
		for(int j=i;j<=n;j++){
			//已经存在 
			if(cards_pos[a[j]]){
				//拿出来 
				while(now_cards[tot]!=a[j]){
					cards_pos[now_cards[tot]]=0;//取消位置
					now_cards[tot]=0;
					tot--;
				}
			}
			//未存在 
			else{
				tot++;
				now_cards[tot]=a[j];
				cards_pos[a[j]]=tot;
			}
		}
		for(int k=1;k<=m;k++){
			if(now_cards[k]) ans[now_cards[k]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
//中华人民共和国万岁！ 
