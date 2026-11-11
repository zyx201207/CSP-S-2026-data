#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0;
char c[200005];
deque<pair<long long,char> >q;
int main(){
	int i;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		q.push_back(make_pair(a[i],c[i]));
	}
	while(!q.empty()){
		if(q.size()==1)q.pop_back();
		if(q.empty())break;
		pair<long long,char>p=q.front();q.pop_front();
		pair<long long,char>t=q.back();
		while(p.first>=t.first){
			if(p.second!=t.second)ans+=t.first;
			p.first-=t.first;
			q.pop_back();
			t=q.back();
		}
		if(p.first==0)continue;
		t.first-=p.first;
		if(p.second!=t.second)ans+=p.first;
		q.pop_back();
		q.push_back(t);
	}
	cout<<ans;
	return 0;
}
