#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,sum,ad;
long long a[N],dis[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i]; 
	}
	sort(a+1,a+1+n);
	ad=sum/n;
	int dis=N,base=0,base_idx=0;
	for(int i=1;i<=n;i++){
		if(abs(a[i]-ad)<dis){
			dis=abs(a[i]-ad);
			base=a[i];base_idx=i;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(base==a[i]){
			cnt++;
		}
		else if(a[i]<base){
			if(m>=base-a[i]){
				cnt++;
				m=m-(base-a[i]);
			}
		}
	}
	cout<<cnt;
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0; 
} 
