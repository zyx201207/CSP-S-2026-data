#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],t[35],cnt,ans;
bool bj[N][40],s[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=32;j++){
			bj[i][j]=a[i]%2;
			if(bj[i][j]==1)t[j]++;
			a[i]/=2;
			if(a[i]<=0)break;
		}
	}
	for(int i=31;i>=1;i--){
		if(t[i]>=m){
			for(int j=1;j<=n;j++){
				if(bj[j][i]==1){
					s[j]=1;
				}
			}
			cnt=i;
			ans+=(1<<(i-1));
			break;
		}
	}
	for(int i=cnt-1;i>=1;i--){
		long long sum=0;
		for(int j=1;j<=n;j++){
			if(s[j]){
				if(bj[j][i]==1){
					sum++;
				}
			}
		}
		//cout<<sum;
		if(sum>=m){
			for(int j=1;j<=n;j++){
				if(s[j]){
					if(bj[j][i]==0){
						s[j]=0;
					}
				}
			}
			ans+=(1<<(i-1));
		}
	}
	cout<<ans;
	return 0;
}  
