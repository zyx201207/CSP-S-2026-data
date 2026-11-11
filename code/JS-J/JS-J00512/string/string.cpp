#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<pair<long long,char>>::iterator IT;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<long long,char>>s(n),t;
	vector<pair<pair<long long,long long>,char>>ss,tt,S,T;
	long long length=0;
	for(int i=0;i<n;i++){
		cin>>s[i].first>>s[i].second;
		length+=s[i].first;
	}
	t=s;
	reverse(t.begin(),t.end());
	long long curl=0,curr=0;
	long long cur=0;
	for(IT it=s.begin();it!=s.end();it++){
		cur+=it->first;
		if(cur>(length>>1)){
			it->first-=cur-(length>>1);
			s.erase(it+1,s.end());
		}
	}
	IT it=s.end();
	it--;
	if(it->first==0)s.erase(it);
	cur=0;
	for(it=t.begin();it!=t.end();it++){
		cur+=it->first;
		if(cur>(length>>1)){
			it->first-=cur-(length>>1);
			t.erase(it+1,t.end());
		}
	}
	it=t.end();
	it--;
	if(it->first==0)t.erase(it);
	IT itl=s.begin(),itr=t.begin();
	long long ans=0;
	length>>=1;
	curl=1;
	for(int i=0;i<s.size();i++){
		curr=curl+s[i].first-1;
		ss.push_back({{curl,curr},s[i].second});
		curl=curr+1;
	}
	curl=1;
	for(int i=0;i<t.size();i++){
		curr=curl+t[i].first-1;
		tt.push_back({{curl,curr},t[i].second});
		curl=curr+1;
	}
	for(int x=0,y=0;x<s.size(),y<t.size();){
		if(s[x].second!=t[y].second){
			int l1=ss[x].first.first,l2=tt[y].first.first;
			int r1=ss[x].first.second,r2=tt[y].first.second;
			if(l1<=l2&&r2<=r1)ans+=r2-l2+1;
			else if(l2<=l1&&r1<=r2)ans+=r1-l1+1;
			else if(l1<=l2&&l2<=r1&&r1<=r2)ans+=r1-l2+1;
			else if(l2<=l1&&l1<=r2&&r2<=r1)ans+=r2-l1+1;
		}
		if(ss[x].first.second<tt[y].first.second){
			x++;
		}
		else {
			y++;
		}
	}
	cout<<ans<<endl;
}
