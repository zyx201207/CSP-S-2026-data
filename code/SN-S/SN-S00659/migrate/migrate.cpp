//SN-S00659 马星辰 西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000010],b[2000010],an[2000010],ans;
struct node{
	int l,id;
};
void bfs(){
	queue<node>q;
	q.push({a[1],1});
	while (!q.empty()){
		node t=q.front();
		q.pop();
		if (t.l); 
		int i = 1;
		while(a[i]>t.l+d){
			if (a[i]);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int pl=1;pl<=t;pl++){
		cin>>n>>d;
		for (int i = 1;i <= n;i++) cin>>a[i],b[i]=a[i]-a[i-1];
		bfs();
	}
	return 0;
}
