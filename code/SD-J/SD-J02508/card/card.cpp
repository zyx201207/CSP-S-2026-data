#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[500010],ans[300010],cnt=1;
int b[300010];
bool qaq=1;
queue<int> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			qaq=0;
		}
	}
	if(qaq){
		int s=1;
		for(int i=1;i<=n+1;i++){
			if(s!=a[i]){
				cout<<i-1<<' ';
				s++;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				cnt=b[a[j]];
				for(int x=1;x<=m;x++){
					if(b[x]>cnt){
						b[x]=0;
					}
				}
			}
			b[a[j]]=cnt;
			cnt++;
		}
		for(int j=1;j<=m;j++){
			if(b[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
