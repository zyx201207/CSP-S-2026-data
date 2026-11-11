#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],b[N]={0},p=1; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i])p=0;
	}
	if(p==1){
		for(int i=1;i<=n;i++){
			p=1;
			for(int j=i;j<=n-1&&p==1;j++){
				if(a[j]==a[j+1]) {
					p=0;
					for(int k=i;k<=j;k++) b[k]++;
					break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			cout<<b[j]<<' ';
		}
	}
	return 0;
}

