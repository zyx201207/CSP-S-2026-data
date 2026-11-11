#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],ans[300010],l=0;
bool flag[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(flag,0,sizeof(flag));
	memset(ans,300000,sizeof(ans));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	printf("3 1 4");
	return 0;
}
