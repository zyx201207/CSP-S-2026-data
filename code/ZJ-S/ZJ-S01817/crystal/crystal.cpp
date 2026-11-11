//check(11451419919810)
//You have no ___!
#include<iostream>
#include<algorithm>
using namespace std;
long long cry[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> cry[i];
	sort(cry+1,cry+n+1);
	int l=1,ans=1;
	long long cnt=0;
	for(int i = 2; i <= n; i++){
		cnt+=(cry[i]-cry[i-1])*(i-l);
		while(cnt>m){
			cnt-=cry[i]-cry[l];
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
