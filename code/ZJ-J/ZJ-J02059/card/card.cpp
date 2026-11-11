#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
const int M = 3e5+10;
int n,m;
int a[N];
int last[M];
int c[N];
int cnt[M];
bool st[M];


void solve1(){
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			if(last[a[i]]>0){
				for(int j=i-1;j>=last[a[i]];j--){
					if(last[a[j]]==j) last[a[j]] = 0;
					c[j] = 1;
				}	
							
			}
			last[a[i]] = i;
		}
		
		for(int i=l;i<=n;i++){
			if(c[i]==0&&st[a[i]]==0){	
				cnt[a[i]]++;
				st[a[i]]=1;
			}
			last[a[i]] = 0;
			c[i] = 0;
		}
		memset(st,0,sizeof st);
	}
	
	for(int i=1;i<=m;i++) cout << cnt[i] << " ";	
	
	return ;
}

void solve2(){
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			if(st[a[i]]==0){
				cnt[a[i]]++;
				st[a[i]] = 1;
			}
		}
		memset(st,0,sizeof st);
		memset(c,0,sizeof c);
	}

	for(int i=1;i<=m;i++) cout << cnt[i] << " ";
	
	return ;
	
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	if(n<=500) solve1();
	else solve2();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
	
}
