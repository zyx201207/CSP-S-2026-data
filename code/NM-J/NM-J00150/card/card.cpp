#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num[n];
	int maxx = 0;
	for(int i = 0;i < n;i++){
		cin>>num[i];
		maxx = max(maxx,num[i]);
	}
	int cnt[maxx+1];
	memset(cnt,-1,sizeof(cnt));
	for(int s = 0;s < n;s++){
		bool ip[maxx+1];
		memset(ip,false,sizeof(ip));
		stack<int> card;
		for(int i = s;i < n;i++){
			if(!ip[num[i]]){
				ip[num[i]] = true;
				card.push(num[i]);
			}else{
				while(card.top() != num[i] && !card.empty()){
					ip[card.top()] = false;
					card.pop();
				}
			}
		}
		for(int i = 1;i <= maxx;i++){
			if(ip[i]){
				cnt[i]++;
			}
		}
	}
	for(int i = 1;i <= maxx;i++){
		if(cnt[i] != -1) cout<<cnt[i]+1<<' ';
	}
	return 0;
}
