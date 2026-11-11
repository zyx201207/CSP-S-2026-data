#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
int n,m,cnt=1;
int a[500005];
int d,flag;
void solve(){
	int p=n;
	int tot=0,k=0,j=p-1;
	while(tot<m && j>=1){
		tot+=(a[p]-a[j]);
		if(tot>m) break;
		j--;
        k++;
	}
    cnt=max(cnt,k+1);
    cout<<cnt;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int d=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(d!=a[i]-a[i-1]){
			flag=1;
			break;
		}
	}
	if(flag==0){
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++){
		int tot=0,k=0,j=i-1;
		while(tot<m && j>=1){
			tot+=(a[i]-a[j]);
			if(tot>m) break;
			j--;
            k++;
		}
        cnt=max(cnt,k+1);
	}
	cout<<cnt;
	return 0;
}
