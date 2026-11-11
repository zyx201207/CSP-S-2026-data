#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#define ll long long

using namespace std;

const int N=1e6+5;
ll tp[N];
ll ys[N];
ll zl[N];
stack<ll>st;
ll tong[N],u=0;
map<ll,ll>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
	ll n,k,mn=1e18,mx=-1e18;
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++){
		cin >> tp[i];
		if (mp[tp[i]]==0){
			mp[tp[i]]=1;
			zl[++u]=tp[i];
		}
	}
	for (int i=1;i<=n-1;i++){
		memset(ys,0,sizeof(ys));
		ll idx=0;
		for (int j=i;j<=n;j++){


			if (ys[tp[j]]!=0){
				ll pp=j-ys[tp[j]];

				while (pp){
					pp--;
					ll t=st.top();
					
					ys[t]=0;
					idx--;

					
					st.pop();
				}
				
			}
			st.push(tp[j]);
			ys[tp[j]]=++idx;
			
			

		}
		while (st.size()){
			tong[st.top()]++;

			st.pop();
		}
	}
	tong[tp[n]]++;
	for (int i=1;i<=u;i++){
		cout << tong[zl[i]]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
