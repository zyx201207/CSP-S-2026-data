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
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#else
	string debug_filename="../../CSP-J/crystal/crystal";
	int debug_sno=1;
	freopen((debug_filename+to_string(debug_sno)+".in").c_str(),"r",stdin);
	freopen((debug_filename+to_string(debug_sno)+".out").c_str(),"w",stdin);
#endif
	return 0;
}
/*
 * hello,i am @gjr19509 on luogu.
 * you may have seen me in NM-J00406,that is also me.
 * as you see,i don't know how to deal with the problems, from T1 to T4.
 * to make my code more meaningful,you can copy it and use it by yourself.
 * it can avoid submitting code with debug output.
 * i learnt to make it from << C++ Primer >>, but the book isn't for OIers.
 * i wrote CSP-J on line 25 because of a mistake when extracting the problems.
 * i thought i could have the first prize of CSP-S in my school,
 * but i don't think 0pts can get a prize.
 * 
 * qwq
 */
