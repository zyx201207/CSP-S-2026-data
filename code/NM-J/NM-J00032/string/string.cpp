#include <bits/stdc++.h>
using namespace std;
int n,a;
char c;
long long ans=0;
deque<pair<int,char> >dq;
pair<int,char> frt,bk;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		dq.push_back(make_pair(a,c));
	}while(dq.size()>1){
		frt=dq.front();
		bk=dq.back();
		if(frt.second!=bk.second){
			ans+=min(frt.first,bk.first);
		}
		if(frt.first>bk.first){
			dq.pop_back();
			frt.first-=bk.first;
			dq.pop_front();
			dq.push_front(frt);
		}else{
			dq.pop_front();
			bk.first-=frt.first;
			dq.pop_back();
			dq.push_back(bk);
		}
	}cout<<ans;
	return 0;
}
