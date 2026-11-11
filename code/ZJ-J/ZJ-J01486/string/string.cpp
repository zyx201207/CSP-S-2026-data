#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
deque<pii >q;
int n;
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		q.push_back({a[i],(int)(c[i])});
	}
	int ans=0;
	while(!q.empty()){
//		cout<<q.size()<<endl;
		pii l=q.front(),r=q.back();
		if(l.second==r.second){
			if(l.first<r.first){
				q.pop_front();
				if(q.empty())break;
				q.pop_back();
				q.push_back({r.first-l.first,r.second});
			}else if(l.first==r.first){
				q.pop_front();
				if(q.empty())break;
				q.pop_back();
			}else{
				q.pop_front();
				if(q.empty())break;
				q.pop_back();
				q.push_front({l.first-r.first,l.second});
			}
		}else{
			if(l.first<r.first){
				ans+=l.first;
				q.pop_front();
				if(q.empty())break;
				q.pop_back();
				q.push_back({r.first-l.first,r.second});
			}else if(l.first==r.first){
				ans+=l.first;
				q.pop_front();
				if(q.empty())break;
				q.pop_back();
			}else{
				ans+=r.first;
				q.pop_front();
				if(q.empty())break;
				q.pop_back();
				q.push_front({l.first-r.first,l.second});
			}
		}
	}
	cout<<ans;
	return 0;
}

