#include<bits/stdc++.h>
using namespace std;
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef long long ll;
const int maxn=5e5+5;
const int Maxn=3e5+5;
ll a[maxn],l[Maxn],num[Maxn];
int main(){
	FASTIO;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[a[i]]=i;
	}
	
	bool flag=true;
	for(int i=1;i<m;i++){
		if(l[i]>l[i+1])flag=false;
	}
	if(flag){
		for(int i=1;i<=m;i++)cout<<n<<' ';
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			num[a[j]]++;
			j=l[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++)cout<<num[i]<<' ';
	return 0;
}
