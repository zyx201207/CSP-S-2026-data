#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<string>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>

using namespace std;
using ll=long long;
using ull=unsigned long long;
using lb=long double;
using pii=pair<int,int>;
using pll=pair<long long,long long>;
using pil=pair<int,long long>;
using pli=pair<long long,int>;

const int N=1e6+9;
int n,m;
int a[N],cnt[N];
vector <int> v;
bool vis[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	for(int i=1; i<=n; i++){
		v.clear();
		memset(vis,0,sizeof(vis));
		
		for(int j=i; j<=n; j++){
			if(vis[a[j]]){
				while(!v.empty() && v.back() != a[j]){
					vis[v.back()]=0;
					v.pop_back();
				}
			}
			else{
				v.push_back(a[j]);
				vis[a[j]]=1;
			}
		}
		
		for(auto x:v){
			cnt[x]++;
		} 
	}
	for(int i=1; i<=m; i++)cout<<cnt[i]<<' ';
	
	return 0;
}