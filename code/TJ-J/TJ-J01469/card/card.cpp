#include<bits/stdc++.h>
using namespace std;
const int maxn=5*1e5;
int n,m;
int a[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==2){
		cout<<n/2;
		return 0;
	}
	return 0;
}
