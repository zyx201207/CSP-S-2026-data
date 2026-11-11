#include<bits/stdc++.h>
using namespace std;
int n,m,t,cnt,maxn=1,ans,sum;
struct node{
	int data;
	int c[35];
}e[200005];
bool cmp(node x,node y){
	return x.data>y.data;
}
int b[35];
queue<node> q,p,q1,bad;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>e[i].data;
		t=e[i].data,cnt=0;
		while(t){
			e[i].c[++cnt]=t%2;
			t/=2;
		}
	}
	for(int i=1;i<=30;i++)maxn*=2;
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n;i++)q.push(e[i]);
	for(int i=31;i>=1;i--){
		q1=q,sum=0;
		while(!q.empty()){
			if(q.front().c[i]==1){
				p.push(q.front());
				sum++;
			}
			q.pop();
		} 
		if(sum>=m){
			ans+=maxn;
			q=p;
		}else{
			q=q1;
		}
		p=bad;
		maxn/=2;
	}
	cout<<ans;
	return  0;
}
