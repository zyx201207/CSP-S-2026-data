#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#define debug printf
#else
int debug(...){return 0;}
#endif

// UNDER CONSTRUCTION (Case 4-6)

struct part{
	long long len;
	char c;
} parts[200005];
int n, pl=1, sl;
long long a; char c;
long long l_pos, l_it, l_end, r_pos, r_it, r_end, ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
#ifndef LOCAL
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
#endif
	cin>>n;
	cin>>parts[0].len>>parts[0].c;
	sl = parts[0].len;
	for(int i=1;i<n;i++){
		cin>>a>>c;
		if(parts[pl-1].c==c) parts[pl-1].len += a;
		else parts[pl++] = {a,c};
		sl += a;
	}
	r_it = pl;
	r_pos = sl;
	#ifdef LOCAL
	for(int i=0;i<pl;i++){
		cout<<i<<":"<<parts[i].len<<" "<<parts[i].c<<endl;
	}
	#endif
	while(l_pos<r_pos){
		l_pos += parts[l_it++].len;
		while(l_pos>=sl-r_pos){
			if(parts[l_it-1].c != parts[r_it-1].c) ans += l_pos-sl+r_pos;
		    r_pos -= parts[--r_it].len;
		}
	}
	if(pl&1 && pl != 1){
		ans -= parts[l_it].len;
		r_pos += parts[l_it].len;
		ans += l_pos-sl+r_pos;
	}
	
	cout<<ans;
	return 0;
}
