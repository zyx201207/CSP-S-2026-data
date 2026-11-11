#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	signed k[1005][505];
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=n;j++){
			k[i][j]=a[i]-a[j];
		}
		
	}
	int aa[505];
	int nees=0;
	bool ck=true;
	for(int i=1;i<=n&&ck;i++){
		nees=0;
		for(int j=1;j<=n;j++){
			if(j>i){
				break;
			}
			nees+=k[i][j];
		}
		if(nees>=m){
			for(int j=1;j<=n;j++){
				aa[j]=k[i][j];
			}
			ck=false;
		}
		
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(m-aa[i]>=0&&aa[i]>=0){
			sum++;
		}
		else{
			break;
		}
	}
	cout<<sum;
	return 0;
}
