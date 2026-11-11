#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int n,m;
int a[N];
int cnt[N];
int test[N],st,ed;
int flag[N],last[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	} 
	for(int i = 1;i <= n;i++){
		memset(test,0,sizeof(test));
		memset(flag,0,sizeof(flag));
		memset(last,0,sizeof(last));
		st = ed = 0;
		for(int j = i;j <= n;j++){
			if(flag[a[j]]){
				int nowst = last[a[j]]+1;
				for(int k=st;k <= last[a[j]];k++){
					flag[a[k]] = 0;
					last[a[k]] = 0;
				}
				st = nowst;
			}
			else{
				flag[a[j]] = 1;
				last[a[j]] = j;
			}
			test[ed++] = a[j];
		}
		for(int  j = st;j <=  ed;j++){
			cnt[test[j]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		cout << cnt[i] << " ";
	} 
	return 0;
}


