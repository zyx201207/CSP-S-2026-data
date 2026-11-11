#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;cin>>n>>m;
	vector<long long>A(n);
	set<long long>st;
	for(int i=0;i<n;i++){
		cin>>A[i];
		st.insert(A[i]);
	}
	sort(A.begin(),A.end());
	int ans=0;
	for(long long t:st){
		long long x=m;
		int cnt=0;
		for(int i=n-1;i>=0;i--){
			if(A[i]<=t&&x>=t-A[i]){
				x-=t-A[i];
				cnt++;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}