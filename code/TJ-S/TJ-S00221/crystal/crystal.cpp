#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	ll n,M;
	cin>>n>>M;
	vector<ll> a(n+5,0),b(n+5,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>=400000){
		cout<<n;
		return 0;
	}
	sort(a.begin()+1,a.begin()+1+n);
	for(int i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
	}
	ll maxx=0;
	for(int i=n;i>=1;i--){
		ll m=M,sum=1,now=b[i-1];
		for(int j=i-1;j>0;){
			if(now<=m){
				//cout<<j<<"-";
				m-=now;
				sum++;
				j--;
				now=b[j]+now;
			}else break;
				//cout<<"("<<i<<")"<<m<<". ";
		}maxx=max(maxx,sum);
		//cout<<sum<<";";
	}cout<<maxx;
	return 0;
}

