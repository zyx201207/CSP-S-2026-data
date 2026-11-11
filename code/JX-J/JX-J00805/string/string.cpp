#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,len,ans;
struct str{
	int a;
	char c;
};
vector<str> a;
deque<str> q1,q2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a.push_back({0,'#'});
	for(int i=1;i<=n;i++){
		int z;
		char c;
		cin>>z>>c;
		a.push_back({z,c});
		len+=z;
	}
	int q=0;
	for(int i=1;q!=len/2;i++){
		int z=min(a[i].a,len/2-q);
		q+=z;
		q1.push_back({z,a[i].c});
	}
	q=0;
	for(int i=n;q!=len/2;i--){
		int z=min(a[i].a,len/2-q);
		q+=z;
		q2.push_back({z,a[i].c});
	}
	
//	cout<<"\n";
//	for(str k:q1){
//		cout<<k.a<<" "<<k.c<<"\n";
//	}
//	cout<<"\n";
//	for(str k:q2){
//		cout<<k.a<<" "<<k.c<<"\n";
//	}
//	cout<<"\n";
	
	while(!q1.empty()&&!q2.empty()){
		int q1a=q1.front().a,q2a=q2.front().a;
		char q1c=q1.front().c,q2c=q2.front().c;
		q1.pop_front(),q2.pop_front();
		if(q1a>q2a){
			q1.push_front({q1a-q2a,q1c});
		}else if(q2a>q1a){
			q2.push_front({q2a-q1a,q2c});
		}
		if(q1c!=q2c){
			ans+=min(q1a,q2a);
		}
	}
	cout<<ans;
	return 0;
}
