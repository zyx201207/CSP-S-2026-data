#include<bits/stdc++.h>
using namespace std;
int n,m,a[200007],maxx=-1,s=0,maxn=-1;
int res[27];
bool b[200007][27],ss[27];
void dfs(int nw,int cnt){
	if(nw > n) return ;
	if(cnt == m){
		int ans = res[1];
		for(int i=2; i<=m; i++)
			ans &= res[i];
		maxn = max(ans,maxn);
		return ;
	}
	res[cnt+1] = a[nw+1];
	dfs(nw+1,cnt+1);
	res[cnt+1] = 0;
	dfs(nw+1,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		maxx = max(a[i],maxx);
		if(i==1) s = a[i];
		else s &= a[i];
	}
	bool fl=0;
	for(int i=1; i<=n; i++){
		int k=0;
		while(a[i] > 0){
			if(a[i]%2==0){
				fl=1;
				break;
			}
			k++;
			a[i]/=2;
		}
		if(fl) break;
	}
	if(!fl){
		sort(a+1,a+n+1);
		cout << a[n-m+1];
	}
	if(n<=20){
		dfs(0,0);
		cout << maxn;
	}else if(n<=2000){
		if(m==1){
			cout << maxx;
		}else if(m==n){
			cout << s;
		}else if(m==2){
			int anss=-1;
			for(int i=1; i<=n; i++)
				for(int j=i+1; j<=n; j++)
					anss = max(anss,a[i]&a[j]);
			cout << anss;
		}
	}else if(m==n-1){
		int minn = 0x3f3f3f3f,mini = 0,ansn=a[1];
		for(int i=1; i<=n; i++){
			int k=0;
			while(a[i] > 0){
				if(a[i]%2==0){
					minn = min(minn,k-1);
					mini = i;
				}
				k++;
				a[i]/=2;
			}
		}
		if(mini!=1){
			for(int i=2; i<=n; i++){
				if(i == mini) continue;
				ansn&=a[i];
			}
			cout << ansn;
		}else if(mini==0x3f3f3f3f){
			cout << s;
		}else{
			ansn = a[2];
			for(int i=3; i<=n; i++)
				ansn&=a[i];
			cout << ansn;
		}
	}
	return 0;
}