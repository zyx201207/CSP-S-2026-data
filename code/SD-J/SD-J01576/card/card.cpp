#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
int cnt[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool shuzi[M]={0};
		queue<int> q;
		for(int j=i;j<=n;j++){
			q.push(a[j]);
			if(shuzi[a[j]]==1){
				for(int l=1;l<=j-1;l++){
					shuzi[q.front()]=0;
					q.pop();
				}
			}
			shuzi[a[j]]=1;
		}
		while(!q.empty()){ 
			cnt[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
