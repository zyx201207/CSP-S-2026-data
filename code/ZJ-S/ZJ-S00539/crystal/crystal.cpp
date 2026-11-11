#include<bits/stdc++.h>
using namespace std ;
long long n , m , maxn=-1 ;
long long cytl[500010] ;
long long grow[500010] ;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m ;
	for(long long i=1;i<=n;i++)cin >> cytl[i] ;
	sort(cytl+1,cytl+n+1);
	for(long long i=1;i<=n;i++)grow[i] = cytl[i] - cytl[i-1] ;
	for(long long fe=1;fe<=n;fe++){
		if(cytl[fe]==cytl[fe+1])continue ;
		long long now = m , spend = 0 , ans = 1 , where = fe-1 ;
		while(where>0&&now>0){
			spend += grow[where+1] ;
			now -= spend ;
			if(now>0){
				ans++ ;
				where-- ;
			}
			if(now==0){
				ans++ ;
				break ;
			}
			if(now<0){
				break ;
			}
		}
		maxn = max(maxn,ans) ;
	}
	cout << maxn ;
	return 0;
} 
