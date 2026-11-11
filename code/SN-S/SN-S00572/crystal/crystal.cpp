#include <bits/stdc++.h>
using namespace std;
long long N,M;
long long A[500010];
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>N>>M;
	for(int i=1;i<=N;i++)cin>>A[i];
	sort(A+1,A+1+N);
	long long cost=0,flag=1,cnt=1,ans=0;
	for(int i=1;i<N;i++){
		cost+=(cnt*(A[i+1]-A[i]));
		cnt++;
		while(cost>M){
			cost-=(A[i+1]-A[flag]);
			cnt--;
			flag++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
