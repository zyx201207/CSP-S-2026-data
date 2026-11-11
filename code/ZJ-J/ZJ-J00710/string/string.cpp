#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
pair<int,char> p[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		int a; cin>>a;
		char c; cin>>c;
		p[i]={a,c};
	}
	int l=1,r=n;
	ll ans=0;
	while(l<=r){
		int al=p[l].first,ar=p[r].first;
		char cl=p[l].second,cr=p[r].second;
//		cout<<l<<' '<<r<<' '<<(cl==cr)<<' '<<al<<' '<<ar<<'\n';
		if(cl!=cr){
			if(al>ar){
				al-=ar;
				r--;
				ans+=ar;
				p[l].first=al;
			} else if(ar>al){
				ar-=al;
				l++;
				ans+=al;
				p[r].first=ar;
			} else if(ar==al){
				ans+=al;
				l++;
				r--;
			}
		} else {
			if(al>ar){
				al-=ar;
				r--;
				p[l].first=al;
			} else if(ar>al){
				ar-=al;
				l++;
				p[r].first=ar;
			} else if(ar==al){
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}