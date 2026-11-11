#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int cnt[M];
struct node{
	int num,id;
}a[N];
void work(int t){
	map<int,int>mp;
	queue<node>q;
	for(int i=t;i<=n;i++)
		q.push(a[i]),
		mp[a[i].num]++;
	while(q.front().id!=n){
		node f=q.front();
		q.pop();
		cout<<f.id<<' ';	
		if(mp[f.num]>2){
			while(!q.empty()){
				mp[q.front().num]--;
				q.pop();
			}
		}
		q.push(f);
	}
	q.pop();
	mp[a[n].num]--;
	while(!q.empty()){
		if(mp[q.front().num])
			cnt[q.front().num]++;
		mp[q.front().num]=0;
		q.pop();
	}
	puts("");
	for(int i=1;i<=m;i++)
		printf("%d ",cnt[i]);
	puts("");
	puts("");
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].num),
		a[i].id=i;
	for(int i=1;i<=n;i++)
		work(i);
	for(int i=1;i<=m;i++)
		printf("%d ",cnt[i]);
	return 0;
}

