#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
class dostream{
public:
	dostream()=default;
	template<typename T>
	dostream& operator<<(const T&);
}dout;
template<typename T>
dostream& dostream::operator<<(const T &x){
#ifdef DEBUG
	clog<<x;
#endif
	return *this;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
#ifndef DEBUG
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#else
	string debug_filename="../../CSP-J/hub/hub";
	int debug_sno=1;
	freopen((debug_filename+to_string(debug_sno)+".in").c_str(),"r",stdin);
	freopen((debug_filename+to_string(debug_sno)+".out").c_str(),"w",stdin);
#endif
	return 0;
}
