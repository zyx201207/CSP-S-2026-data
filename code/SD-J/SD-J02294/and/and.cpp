#include <iostream>

using namespace std;

const int N=200005;
int n,m;
int a[N];
int dp[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		dp[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			if(j!=i){
				dp[j]=max(dp[j],(a[j]&a[i]));
			}
		}
	}
	cout << dp[m] << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
