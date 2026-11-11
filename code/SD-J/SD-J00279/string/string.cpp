#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<int,char> >s;
	for(int i=0;i<n;i++){
		int a;char c;
		cin>>a>>c;
		s.push_back({a,c});
	}int l1=0,l2=0,r1=n-1,r2=0;
	while(l1<r1||(l1==r1&&l2+r2<=s[l1].first)){
		int ls=s[l1].first-l2;
		int rs=s[r1].first-r2;
		int mn=min(ls,rs);
		char lc=s[l1].second;
		char rc=s[r1].second;
		if(lc!=rc)ans+=mn;
		l2+=mn;r2+=mn;
		if(l2==s[l1].first){
			l1++;
			l2=0;
		}
		if(r2==s[r1].first){
			r1--;
			r2=0;
		}
	}
	cout<<ans;
	return 0;
}
