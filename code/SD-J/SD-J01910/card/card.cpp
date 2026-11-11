#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=0;
	while(x<=n){
		x++;
		int ans[N]={0},cnt=0;
		for(int i=x+1;i<=n;i++){
			if(a[i-1]!=a[i]){
				ans[++cnt]=a[i];
			}else{
				ans[N]={0};
				ans[1]=a[i];
				cnt=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<0<<" ";
	}
	return 0;
}

