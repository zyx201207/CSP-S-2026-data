#include <bits/stdc++.h>
using namespace std;
long long A[500100],dp[500100];
long long i,j,o,n,m,maxx,sum,ans,sam,s;
void query(){
	long long i,j;
	for(i = 1 ; i < n ; i++){
		dp[i] = A[i + 1] - A[i];
	}
}
int cha(){
	long long i,j,s1,s2;
	s1 = A[n] - A[n - 1];
	for(i = n - 1 ; i > 1 ; i--){
		s2 = A[i] - A[i - 1];
		if(s1 != s2) return 0;
	}
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n>>m;
	maxx = 1;
	for(i = 1 ; i <= n ; i++){
		cin>>A[i];
	}
	sort(A + 1 , A + 1 + n);
	if(cha() == 1){
		s = A[n] - A[n - 1];
		if(s == 0){
			cout<<n;
		}
		else{
			for(i = 1 ; i <= n ; i++){
				sum += s * i;
				if(sum > m){
					maxx = i;
					break;
				}
				if(sum == m){
					maxx = i + 1;
					break;
				}
			}
			cout<<maxx;
		}
	}
	else{
		query();
		for(i = 2 ; i <= n ; i++){
			if(dp[i - 1] > m) continue;
			if(A[i] == A[i + 1]){
				for(o = i ; o <= n ; o++){
					if(A[o] != A[i]){
					    i = o - 1;
					    break;
					}
				}
			}
			ans = 1;
			sum = 0;
			sam = 0;
			for(j = i - 1 ; j >= 1 ; j--){
				sam += dp[j];
				sum += sam;
				ans++;
			//	cout<<sum<<" "<<sam<<" "<<ans<<endl;
				if(sum > m){
					sum -= dp[j];
					ans--;
					maxx = max(maxx , ans); 
					break;
				}
				else if(sum == m){
					maxx = max(maxx , ans);
					break;
				}
			}
		}
		cout<<maxx;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
