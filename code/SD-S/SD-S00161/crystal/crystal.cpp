#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
const int N=5e5+100;
bool cmp(int a,int b){return a<b;}
int n,m,ns[N],tot=0,sum=0,ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> ns[i];
	}
	sort(ns,ns+n,cmp);
	for(int i=0,j=0;j<n;j++){
		sum+=ns[j];
		if(j>i) tot+=(ns[j]-ns[j-1])*(j-i);
		while(tot>m){
			tot-=ns[j]-ns[i];
			sum-=ns[i];
			i++;
		}
		ans=max(ans,j-i+1);
	}
	cout << ans;
	return 0;
}
