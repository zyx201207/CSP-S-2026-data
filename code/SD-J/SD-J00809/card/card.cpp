#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[200005],top,p[200005],q[200005],ans[100005];
bool vis[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		top=0;
		for(int j=i;j<=n;j++){
			int t=a[j];
			if(!vis[t]){
				vis[t]=1;
				p[t]=top+1;
				q[++top]=t;
			} 
			else{
				for(int k=p[t]+1;k<=top;k++) vis[q[k]]=0;
				top=p[t];
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=vis[j];
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m) cout<<' ';
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
fc card1.ans card1.out /n
fc card2.ans card2.out /n
fc card3.ans card3.out /n
fc card4.ans card4.out /n
fc card5.ans card5.out /n
fc card6.ans card6.out /n
finished.
*/
