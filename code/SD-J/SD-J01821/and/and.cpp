#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll A[1000001],F[1000001],G[1000001];
ll n,m,ans=-9999;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> A[i];
	} 
	sort(A+1,A+1+n);
	for(int i = 1;i <= n;i++){
		F[i]=A[i];
	} 
	for(int i = 2;i <= m;i++){
		for(int j = i;j <= n;j++){
			for(int k = 1;k < j;k++){
				G[j]=max(G[j],A[j]&F[k]);
			} 
		}
		for(int j = 1;j <= n;j++){
			F[j]=G[j];
			G[j]=0;
		}
	}
//	for(int i = 1;i <= n;i++){
//		cout << G[i] << ' ';
//	}
//	cout << endl;
//	for(int i = 1;i <= n;i++){
//		cout << F[i] <<' ';
//	}
//	
	for(int i = 1;i <= n;i++){
		ans = max(F[i],ans);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
Trick||Treat!
17 18D 17 17F
6
 1000000000 a
 1000000000 a
 1000000000 a
 1000000000 b
 1000000000 b
 1000000000 b
*/
