#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],cnt[500100],book[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!book[a[i]]) book[a[i]]=i;
		if(!cnt[a[i]]) cnt[a[i]]=i;
		else{
			for(int j=i+1;j<book[a[i]];j++){
				cnt[a[j]]--;
				book[a[j]]=0;
			}
			book[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
}
