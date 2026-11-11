#include<iostream>
#include<vector>
#include<deque>
using namespace std;
#define int long long
#define frt dq.front()
#define bck dq.back()
struct pstring{
	int a;
	char c;
};
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	int n,ta,res=0;char tc;
	cin>>n;
	deque<pstring> dq;
	while(n--){
		cin>>ta>>tc;
		dq.push_back({ta,tc});
	}
	while(!dq.empty()){
		if(frt.a>bck.a){
			if(frt.c!=bck.c)
				res+=bck.a;
			frt.a-=bck.a;
			dq.pop_back();
		}
		else if(frt.a==bck.a){
			if(frt.c!=bck.c)
				res+=frt.a;
			dq.pop_back();
			if(!dq.empty())
				dq.pop_front();
		}
		else{
			if(frt.c!=bck.c)
				res+=frt.a;
			bck.a-=frt.a;
			dq.pop_front();
		}
	}
	cout<<res<<'\n';
	return 0;
}