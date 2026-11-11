#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5*1e5+5;


vector<ll> B;
vector<ll> C;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	ll n,m;
	cin>>n>>m;
	vector<ll> A(n);
	
	for(ll i=0;i<n;i++) cin>>A[i];
	sort(A.begin(),A.end());

	for(ll i=0;i<n-1;i++){
		ll nt=A[i+1]-A[i];
		B.push_back(nt);
	}
	
	ll fmid=n/2,fcnt=0;
	for(ll i=0;i<fmid;i++) fcnt+=B[i];
	C.push_back(fcnt);
	for(ll i=1;i<fmid;i++){
		C.push_back(fcnt-B[i-1]),fcnt-=B[i-1];
	}
	C.push_back(0);
	//for(auto c:C) cout<<c<<' ';
//	for(auto c:A) cout<<c<<' ';
//	cout<<'\n';
//	for(auto c:B) cout<<c<<' ';
//	cout<<'\n';
	ll ftot=0;
	for(int i=0;i<fmid;i++) ftot+=C[i];
	if(ftot==m) cout<<fmid+1;
	else {
		int asdsad=0;
		ll tot=ftot;
		ll mid=n/2;
		cout<<'\n';
		ll rt=0;
		while(mid<=n-1){
			if(rt>1) break;
			if(mid==n-1)rt++;
			C.clear();
			if(tot<m){
				if(mid==1){
					
				}
				tot=0;
				for(ll i=0;i<mid;i++) C.push_back(A[mid]-A[i]);
				C.push_back(0);
				for(ll i=0;i<mid;i++) tot+=C[i];
				mid/=2;
			}else{
				tot=0;
				ll cnt=0;
				for(ll i=0;i<mid;i++) C.push_back(A[mid]-A[i]);
				C.push_back(0);
				for(ll i=n/2;i<mid;i++){
					ll awa=abs(A[i]-A[mid]);
					C.push_back(awa);
				}
				for(ll i=0;i<mid;i++) tot+=C[i];
				mid+=(n-mid)/2;
			}
			
		}
		int aaa=0;
		for(ll i=mid;i>0;i--){
			aaa+=C[i];
			if(aaa>m) {
				cout<<mid-i;
				return 0;
			}
		}
	}
	//cout<<'\n'<<tot;
	return 0;
}
//Code By Mcg
