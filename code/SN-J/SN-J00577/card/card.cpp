#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 10;
int n, m;
int a[maxn];
int cnt[maxn], ans[maxn], cha[maxn], x[maxn], e[maxn];
bool flag = 1;
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		if(!(a[i] >= a[i - 1]))
			flag = 0;
	}
	if(flag){
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++)
				x[a[j]] = 1;
			for(int j = 1;j <= m;j++)
				e[j] += x[j], x[j] = 0;
		}
		for(int i = 1;i <= m;i++)
			cout<<e[i]<<' ';
		cout<<"\n";
		return 0;
	}
	else{
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++){
				for(int k = i;k < j;k++)
					if(a[k] == a[j]){
						int pos = k;
						for(int t = pos;t < j;t++)
							cnt[a[t]]--;
					}
				cnt[a[j]]++;
			}
			for(int j = 1;j <= n;j++)
				if(cnt[a[j]] != 0)
					ans[a[j]]++;
			memset(cnt, 0, sizeof cnt);
		}
		for(int i = 1;i <= m;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
//CCF = Chinese Can FLY!!! = CPL Can FLY!!!!!!!

