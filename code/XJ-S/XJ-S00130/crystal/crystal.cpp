#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5*1e5;
int a[N];
ll n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int cnt=0,tmp=0;
	cin>>n>>m;ll m1=m;
	for(int i=0;i<n-1;++i){
		cin>>a[i];
	}
	
	for(int i=0;i<n;++i){
		cout<<"第"<<i<<"轮外循环"<<"\n"; 
		int l=0;
		for(int j=0;j<n;++j){
			cout<<"第"<<j<<"轮内循环"<<"\n"; 
			if(a[j]==a[i]){
				l++;
			}
			else if(abs(a[j])<a[i] && abs(a[i]-a[j])<=m){
				m-=(a[i]-a[j]);
				l++;
			}
			cout<<a[i]<<" "<<a[j]<<" "<<l<<" "<<cnt<<"\n";
			cnt=max(l,cnt);
		}
		cnt=max(l,cnt);
		m=m1;
	}
	cout<<cnt;
	return 0;
}

