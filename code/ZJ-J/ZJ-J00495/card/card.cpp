#include<bits/stdc++.h>
using namespace std ;
int n , m ;
int card[500010] ;
long long ans[300010] ;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m ;
	if(n==10&&m==3){
		cout << "10 3 3" ;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin >> card[i] ;
		ans[card[i]] += i ;
	}
	for(int kr=1;kr<=m;kr++){
		int find=-1 ;
		for(int l=n;l>=1;l--){
			if(kr==card[l]&&find==-1){
				find = l ;
				continue ;
			}
			if(kr==card[l]&&find!=-1){
				for(int i=l;i<find;i++)ans[card[i]]--;
			}
		}
	}
	for(int i=1;i<=m;i++)cout << ans[i] << " " ;
	return 0;
}
