//chenzehao xianfulunzhongxue SN-J00743
#include<bits/stdc++.h>
using namespace std;

int main(){
	
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int a[10000000005];
	int n,m;
	cin>>n>>m;
	int c;
	int maxn=0;
	for( int i=1;i<=n;i++){
		cin>>c;
		a[i]=c;
		maxn=max(maxn,a[i]);
	}
	cout<<maxn;


	return 0;
}
