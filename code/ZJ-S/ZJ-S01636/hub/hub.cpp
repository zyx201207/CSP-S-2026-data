#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define sca scanf
#define pri printf
using namespace std;
const int N=1e6+100;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,z,n,k;
	sca("%d%d",&c,&t);
	while(t--){
		sca("%d%d",&n,&k);
		for(int i=1;i<n;i++)sca("%d%d",&z,&z);
		pri("%d\n",n/k-1);
	}
	return 0;
}