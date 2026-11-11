#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	vector<long long>a(n+1,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	long long ans=-1;
	for(int i=n;i>=1;i--){
		long long sum=0;
		int cnt=0;      
		for(int j=i;j>=1;j--){
			sum=sum+a[i]-a[j];
			if(sum>m)break;
			cnt++;
		}
		//ans=max(ans,cnt);
		if(ans<cnt)ans=cnt;
	}
	cout<<ans<<endl; 
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
