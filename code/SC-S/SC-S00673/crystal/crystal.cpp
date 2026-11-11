#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=1e4+10;
int n;ll m;
ll a[N],d[N][N],s[N];
void spe_solve(ll dc){
	int cnt=1;
	int base=dc;
	while(m>0){
		m-=base;
		if(m>=0){
			cnt++;
			base+=dc;
		}
	}
	cout<<cnt;
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll sum=0;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll dc=a[2]-a[1];
	int flagg=1;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=dc)flagg=0;
	}
	if(flagg==1){
		spe_solve(dc);
		return 0;
	}
	int max_ans=1;
	for(int i=1;i<=n;i++){//target
		for(int j=i;j>=1;j--){
			d[i][j]=a[i]-a[j];
		}
		ll temp=m;
		int tot=i;
		int cnt=0;
		while(temp>0){
			if(tot>0&&(temp-d[i][tot])>=0){
				temp-=d[i][tot];
				tot--;
				cnt++;
			}
			else break;
		}
		max_ans=max(max_ans,cnt);
	}
	cout<<max_ans;
	return 0;
} 