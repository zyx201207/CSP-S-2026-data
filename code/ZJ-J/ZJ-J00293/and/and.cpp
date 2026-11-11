#include <bits/stdc++.h>
using namespace std;
long long maxn=0;
int n,m;
int a[200005];
queue <int> q;
void gui(int c){
	if(c==0)return ;
	for(int i=q.front();i<=n;i++){
		long long pdf=a[q.front()];
		c--;
		pdf=pdf&a[i];
		q.push(i);
		maxn=max(maxn,pdf);
		gui(c--);
		c++;
		q.pop();
	}
}
int main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	q.push(1);
	gui(m);
	cout<<maxn;
}