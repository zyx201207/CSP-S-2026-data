#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=2e5+5;
int n,x,sfr,sba;
ull ans;
char ch;
deque<pair<char,pair<int,int> > >dq;
pair<char,pair<int,int> >fr,ba;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>ch;
		if(!dq.empty()) dq.push_back({ch,{dq.back().second.second+1,dq.back().second.second+x}});
		else dq.push_back({ch,{1,x}});
	}
	while(dq.size()>1){
		fr=dq.front();
		ba=dq.back();
		dq.pop_front();
		dq.pop_back();
		sfr=fr.second.second-fr.second.first+1;
		sba=ba.second.second-ba.second.first+1;
//		cout<<fr.first<<" "<<fr.second.first<<" "<<fr.second.second<<" "<<ba.first<<" "<<ba.second.first<<" "<<ba.second.second<<"\n";
		if(sfr>sba){
			if(fr.first!=ba.first) ans+=sba;
			dq.push_front({fr.first,{fr.second.first+sba,fr.second.second}});
		}else if(sfr==sba){
			if(fr.first!=ba.first) ans+=sba;
		}else{
			if(fr.first!=ba.first) ans+=sfr;
			dq.push_back({ba.first,{ba.second.first,ba.second.second-sfr}});
		}
//		cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}