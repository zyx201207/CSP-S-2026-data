#include<bits/stdc++.h>
using namespace std;
//typedef long long LL;
const int N=1e5;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,ans;
	cin>>c>>t>>n;
	for(int i=1;i<=n;i++)
		ans=rand()%N;
	printf("%d",ans);
	return 0;
}

