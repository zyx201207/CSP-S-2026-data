#include<iostream>
#include<deque>
#define int long long
#define PIC pair<int,char>
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	deque<PIC>dq;
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		dq.push_back({a,c});
	}
	int ans=0;
	while(dq.size()>1){
		PIC h=dq.front();
		PIC t=dq.back();
		dq.pop_front();
		dq.pop_back();
		if(h.first>t.first){
			ans+=t.first*(h.second!=t.second);
			dq.push_front({h.first-t.first,h.second});
		}else if(h.first<t.first){
			ans+=h.first*(h.second!=t.second);
			dq.push_back({t.first-h.first,t.second});
		}else{
			ans+=h.first*(h.second!=t.second);
		}
	}
	cout<<ans<<endl;
	return 0;
}
