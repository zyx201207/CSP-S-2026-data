#include <bits/stdc++.h>
#define int long long
#define fir first
#define sec second
#define pic pair<int,char>
using namespace std;
int n,ans;
deque<pic> dq;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int num;char alp;
		cin>>num>>alp;
		dq.push_front({num,alp});
	}
	while(dq.size()>=2){
		pic a=dq.front(),b=dq.back();
		dq.pop_front(),dq.pop_back();
		if(a.sec!=b.sec)ans+=min(a.fir,b.fir);
		if(a.fir>b.fir){
			dq.push_front({a.fir-b.fir,a.sec});
		}
		else if(b.fir>a.fir){
			dq.push_back({b.fir-a.fir,b.sec});
		}
	}
	cout<<ans<<endl;
	return 0;
}
