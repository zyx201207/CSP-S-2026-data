#include<bits/stdc++.h>//PAC 45 scores
using namespace std;
long long n,m;
vector<long long> a;
int check(int goal){
	int mid=upper_bound(a.begin(),a.end(),goal)-a.begin()-1;
	int cnt=0,ans=0;
	for(int i=mid;i>=0;i--){
		if(cnt+goal-a[i]<=m)cnt+=goal-a[i],ans++;
		else break;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	a.resize(n+1);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	int maxcnt=0;
	for(int i=0;i<n;i++){
		int t=check(a[i]);
		if(t>=maxcnt)maxcnt=t;
	}
	cout<<maxcnt<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
