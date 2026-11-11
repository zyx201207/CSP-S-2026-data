#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	vector<pair<ll,char>> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	vector<pair<ll,char>> b=a;
	ll res=0;
	reverse(b.begin(),b.end());
	for(int i=0,j=0;i<n&&j<n;){
		if(a[i].second==b[j].second){
			ll A=a[i].first,B=b[j].first;
			a[i].first=max(A-B,0LL);
			b[j].first=max(B-A,0LL);
		}
		else{
			ll A=a[i].first,B=b[j].first;
			res+=min(A,B);
			a[i].first=max(A-B,0LL);
			b[j].first=max(B-A,0LL);
		}
		if(a[i].first==0) i++;
		if(b[j].first==0) j++;
	}
	cout<<res/2<<endl;
	return 0;
}
