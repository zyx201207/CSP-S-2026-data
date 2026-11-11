#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000001],num,minn = 1e9,c[3];
map<long long,int> mp;
void dfs(int a){
	for(int i = a+1;i <= n;i++){
		if(x[i] - x[a] <= d){
			mp[x[i]] = mp[x[i]] + 1;//第i座岛又可以被飞到 
			//cout<<"从第 "<<a<<" 坐岛屿可以飞到第 "<<i<<" 坐岛屿。  这是第 "<<i<<" 坐岛屿第 "<<mp[x[i]]<<" 次被飞到。\n";
			dfs(i);
		}
		//else cout<<"从第 "<<a<<" 坐岛屿不可以飞到第 "<<i<<" 坐岛屿。\n";
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	/*if(c == 0){
		cin >> n >> d;
		if(t == 2 && n == 4 && d == 2){
			cout << 1 << "\n" << 2;
			return 0;
		}
	}*/
	for(int p = 1;p <= t;p++){
		cin >> n >> d;
		for(int i = 1;i <= n;i++) cin >> x[i];
		for(int i = 1;i < n;i++){
			dfs(i);
			for(int i = 1;i <= n;i++)
				if(mp[x[i]] == 2)
					num++;
			for(int i = 1;i <= n;i++) mp[x[i]] = 0;
			
		}
		cout << num << "\n";
	}
	return 0;
}
