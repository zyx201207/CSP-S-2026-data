#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int c[32],num[N];
bool a[N][32],b[N];
void turn(int n,int i){
	int k=0;
	while(n){
		a[i][k]=n%2;
		c[k]+=n%2;
		n/=2;
		k++;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		turn(num[i],i);
	}
	int has=n;
	for(int i=30;i>=0;i--){
		if(c[i]>=m){
			for(int j=1;j<=n;j++){
				if(!a[j][i]&&!b[j]){
					b[j]=1;
					has--;
					for(int k=0;k<=30;k++){
						if(a[j][k]==1){
							c[k]--;
						}
					}
				}
			}
		}
		if(has<=m){
			break;
		}
	}
	int ans=pow(2,31)-1;
	for(int i=1;i<=n;i++){
		if(!b[i]){
			ans=(ans&num[i]);
		}
	}
	cout<<ans;
	return 0;
}
