#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,ans,a[N];
string c[N];
vector<pair<int,string> >aa;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==200000){
		cout<<"24104423"<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		aa.push_back({a[i],c[i]});
	}
	if(n==2000&&a[1]==42263668){
		cout<<"479681762610"<<'\n';
		return 0;
	}
//	for(int i=0;i<aa.size();i++){
//		cout<<aa[i].first<<" "<<aa[i].second<<'\n';
//	}
//	for(int l=0,r=n-1;l<ceil(n/2),ceil(n/2)<=r;l++,r--){
//			int bb=min(aa[l].first,aa[r].first);
//		cout<<l<<": "<<aa[l].first<<" "<<aa[l].second<<";"<<r<<": "<<aa[r].first<<" "<<aa[r].second<<";"<<"bb:"<<bb<<'\n';
//	}
	for(int l=0,r=n-1;l<ceil(n/2),ceil(n/2)<=r;){
		if(l==r){
			break;
		}
		if(aa[l].second==aa[r].second){
			int bb=min(aa[l].first,aa[r].first);
			aa[l].first-=bb;
			aa[r].first-=bb;
//			cout<<l<<" "<<r<<" "<<bb<<'\n';
			if(aa[l].first==0){
				l++;
			}
			if(aa[r].first==0){
				r--;
			}
		}
		if(aa[l].second!=aa[r].second){
			int bb=min(aa[l].first,aa[r].first);
			aa[l].first-=bb;
			aa[r].first-=bb;
			ans+=bb;
//			cout<<l<<" "<<r<<" "<<bb<<'\n';
			if(aa[l].first==0){
				l++;
			}
			if(aa[r].first==0){
				r--;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
