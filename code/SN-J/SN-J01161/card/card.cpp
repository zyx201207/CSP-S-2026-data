#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[300005];
long long b[200005];
bool vis[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		cout<<k<<" "<<k<<endl;
	}
	return 0;
} 
