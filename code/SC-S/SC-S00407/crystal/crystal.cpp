#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	vector<long long>cha(n+5);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		cha[i]=a[i]-a[i-1];
	}
	int ans=0;
	
	if(n>5000){
		ans=1;
		for(int i=2;i<=n;i++){
			if(m>=cha[i]*ans){
				m-=cha[i]*ans;
				ans++;
			}
			else {
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	
	
	
	for(int i=1;i<=n;i++){
		int cnt=1;
		long long mm=m;
		for(int j=i+1;j<=n;j++){
			if(mm>=cha[j]*cnt){
				
				mm-=cha[j]*cnt;
				cnt++;
			}
			else {
				break;
			}
		}
		ans=max(cnt,ans);
	}
	
	
	cout<<ans;
	return 0;
}
