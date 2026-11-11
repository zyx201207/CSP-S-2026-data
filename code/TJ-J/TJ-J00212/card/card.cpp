#include <bits/stdc++.h>
using namespace std;
long long n,m,vis[300005],used[300005],a[300005],cnt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for (int i = 1;i <= n;i++){
		cin >>a[i];
//		int x=a[i];
//		if (vis[x]==0){
//			f[i]=-1; 
//		}
//		else f[i]=vis[a[i]];
//		vis[a[i]]=i;
	}
//	for (int i = 1;i <= n;i++){
//		cout <<f[i]; 
//	}
//	cout <<endl;
	queue<int>q;
	for (int i = 1;i <= n;i++){
		
		for (int j = i;j <= n;j++){
			int t=a[j];
			int s = q.size();
//			cout <<s<<' ';
			int f =0;
			for (int k = 1;k <= s;k++){
				int x = q.front();
				q.pop();
				if (x==t){
					f = 1;
				}
				if (f==0)q.push(x);
//				else cout <<x<<' ';
			}
			q.push(t);
//			cout <<q.size()<<' ';
		}
		while(!q.empty()){
			cnt[q.front()]++;
//			cout <<q.front()<<' ';
			q.pop();
		}
//		cout <<endl;
	}
	for (int i = 1;i <= m;i++){
		cout <<cnt[i]<<' ';
	}
	return 0;
}
