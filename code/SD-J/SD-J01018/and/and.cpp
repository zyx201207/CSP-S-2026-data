#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define ull unsigned long long
#define int long long
using namespace std;
set<int>s;
vector<int>vc;
const int N=2e5+50;
int a[N];
bool tsA=1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=INT_MAX;
	int maxx=-100;
	int maxxx=-100;
	int minn=LLONG_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s.insert(a[i]);
		sum=sum&a[i];	
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
		vc.push_back(a[i]);
		if(signed(log2(a[i]+1))!=log2(a[i]+1)){
			tsA=0;
		}
	}
	sort(vc.begin(),vc.end());
	if(m==n){
		cout<<sum;
	}
	else if(m==1){
		cout<<maxx;
	}
	else if(tsA){
		cout<<vc[n-m];
	}
	else if(maxx<4){
		auto it_1=s.find(1);
		auto it_2=s.find(2);
		auto it_3=s.find(3);
		bool hone=it_1!=s.end(),htwo=it_2!=s.end(),hthree=it_3!=s.end();
		if(m==1){
			if(hthree){
				cout<<3;
			}
			else if(htwo){
				cout<<2;
			}
			else{
				cout<<1;
			}
		}
		else if(m==2){
			if(hthree){
				if(htwo){
					cout<<2;
				}
				else if(hone){
					cout<<1;
				}
			}
			else {
				cout<<0;
			}	
		}
		else{
			cout<<0;
		}
	}
	else{
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				maxxx=max(maxx,a[i]&a[j]);
			}
		} 
		cout<<maxxx;
	}
    return 0;
}
//n!
//-------
//m!(n-m)!

//a&b&c&c=a&b%c! 2^a-1 & 2^b-1 =min(2^a-1,2^b-1)!
// 01
// 10
// 11
//
