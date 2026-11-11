#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n;
int m,maxn;
int s[200010],last_cnt[50],fa_pow[50],ans;
struct r{
	vector<int> id;
}cnt[50];
void  yru(int x,int i){
	int sum = 0;
	while(x){
		sum++;
		if(x % 2)
		{
			cnt[sum].id.push_back(i);
		}
		x >>= 1;
	}
}
void dabiao_pow(){
	for(int i = 0 ; i <= 30 ; i ++){
		fa_pow[i] = pow(2,i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; ++ i)
	{
		cin >> s[i];
		yru(s[i],i);
	}
		if(m == 1)
	{
		cout << maxn;
		return 0;
	}
	if(m == n)
	{
		maxn = s[1];
		for(int i = 2 ; i <= n ; i ++){
			maxn &= s[i];
		}
		cout << maxn;
		return 0;
	}
	if(m == 2 && n <= 2000){
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= n ; j ++)
			{
				if(i == j){
					continue;
				}
				maxn = s[i] & s[j];
				ans = max(maxn , ans);	
			}
		}
		cout << ans ;
		return 0;
	}
	dabiao_pow();
//	for(int i = 0 ; i <= 30 ; i ++){
//		cout <<fa_pow[i]<<endl;
//	}
	for(int i = 35 ; i >= 1 ; i --)
	{
		if(cnt[i].id.empty()){
			continue;	
		}
		if(cnt[i].id.size() < m){
//			cout << i << ' ';
			for(int j = 0 ; j <cnt[i].id.size() ; j ++){
//				cout << s[cnt[i].id[j]]<<'-'<<fa_pow[i-1]<<"      " ;
				s[cnt[i].id[j]] -= fa_pow[i-1];
			}
//			cout << endl;
		} 
	}
	for(int i = 1 ; i <= n ; i ++){
		maxn = max(maxn,s[i]);
	}
	cout << maxn;
//	for(int i = 1 ; i <= n ; i ++){
//		cout << s[i] << ' ';
//	}
//		sort(cnt[i].id.begin(),cnt[i].id.end(),greater<int>());
//		cout << i <<':';
//		for(int j = 0 ; j < cnt[i].id.size() ; j ++)
//		{
//			cout << cnt[i].id[j]<<" ";
//		}
//		cout << endl;
	return 0;
}
