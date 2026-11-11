#include<bits/stdc++.h>
using namespace std;
long long n,m;
queue<long long>q;
long long s[500005],q1[500005],cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		q1[i]=a;
	}for(int f=1;f<=n;f++){
		for(int i=f;i<=n;i++){
			q.push(q1[i]);
		}
		for(int i=f;i<=n;i++){
			for(int j=f;j<=n;j++){
				if(s[j]==q.front()){
					for(int k=j;k<=n;k++)s[k]=0;
				}
			}s[i]=q.front();
			q.pop();
		}for(int i=f;i<=n;i++)
			cnt[s[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}