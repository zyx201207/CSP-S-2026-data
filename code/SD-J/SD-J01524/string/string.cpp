#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,tot=1;
	cin>>n;
	vector<pair<char,int>> p(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}
	for(int i=1;i<=n;i++){
		p[tot].second+=a[i];
		if(i==n){
			p[tot].first=c[i];
			continue;
		}
		if(c[i]!=c[i+1]) p[tot].first=c[i],tot++;
 }
//	for(int i=1;i<=tot;i++) cout<<p[i].first<<"*"<<p[i].second<<endl;
	int ban=tot/2+tot%2,ans=0;
	for(int i=1;i<=ban;i++){
		if(p[i].first==p[tot-i].first&&p[i].second==p[tot-i].second){
			continue;
		} 	
//		
		int xian=tot-i+1-(p[i].first==p[tot-i].first);
		while(p[xian].second!=p[i].second&&xian>=i){
			if(p[xian].second<p[i].second){
				p[xian].first=p[i].first;
				ans+=p[xian].second;
				if(p[xian].first==p[xian+1].first) p[xian].second+=p[xian+1].second,tot--;
			}
			if(p[xian].second>p[i].second){
				int zhuan=p[xian].second-p[i].second;
				ans+=zhuan;
				p[xian].second=p[i].second;
				p[xian-1].second+=zhuan;
			}
			xian--;
		}
//		
//		cout<<i<<" "<<xian<<"*******************"<<endl;
//		for(int j=1;j<=tot;j++) cout<<p[j].first<<""<<p[j].second<<endl;
//		cout<<endl;
	} 
	cout<<ans;
	return 0;
}
