#include<bits/stdc++.h>
#define IO freopen("card.in","r",stdin);freopen("card.out","w",stdout);
using namespace std;
const int MAXN=5e5+10;
const int MAXM=3e5+10;
long long int A[MAXN];
long long int vis[MAXM];
vector<int>wh[MAXM];
int main(){
	IO
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		wh[A[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int cnt=i;
		while(cnt<=n){
			vis[A[cnt]]++;
			cnt=wh[A[cnt]][wh[A[cnt]].size()-1]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<vis[i]<<' ';
	return 0;
}

