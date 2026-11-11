#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int pos[30],c,n,m,a[200005],maxx=0;
priority_queue<int> q;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		q.push(a[i]); 
		maxx=max(maxx,a[i]);
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	int x=q.top();
	q.pop();
	while(x!=0){
		pos[++c]=(x%2);
		x/=2;
	}
	int l=0;
	for(int i=2;i<=m;i++){
		int x=q.top();
		q.pop();
		int p[30],t=0;
		memset(p,0,sizeof(p));
		while(x!=0){
			p[++t]=(x%2);
			x/=2;
		}
		l=max(t,c);
		for(int j=1;j<=l;j++){
			if(p[j]!=pos[j]){
				pos[j]=0;
			}
		}
		c=l;
	}
	int cnt=0;
	int ans=1;
	for(int i=1;i<=l;i++){
		if(i==1){
			ans=1;
		}else{
			ans*=2;
		}
		cnt+=(ans*pos[i]);
	}
	cout<<cnt;
	return 0;
}
