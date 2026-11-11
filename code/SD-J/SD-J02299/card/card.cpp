#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define x1 x_1
#define x2 x_2
#define y1 y_1
#define y2 y_2
using namespace std;

long long read(){
	char ch=getchar();
	long long res=0;
	int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	return res*f;
}
int n,m;
int a[505];
int vis[505];
int cnt[505];
int main(){
	//一定一定要记得初始化！！！！！
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
    	a[i]=read();
	}
	deque<int>q;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			//q.push(a[j]);
			if(vis[a[j]]){
				while(!q.empty()){
					int kkk=q.back();
					q.pop_back();
					if(kkk==a[j]) break;
					else vis[kkk]--;
				}
			}
			else vis[a[j]]++;
			q.push_back(a[j]);
		}
		while(!q.empty()){
			int x=q.front();
			cnt[x]++;
			q.pop_front();
		}
		
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}

