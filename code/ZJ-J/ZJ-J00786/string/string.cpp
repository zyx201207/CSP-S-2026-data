#include <bits/stdc++.h>
using namespace std;
typedef long long inte;
struct Sep{
	inte l, r;
	char c;
	Sep(inte l, inte r, char c): l(l), r(r), c(c){};
};
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<Sep> v;
	inte len=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		v.push_back(Sep(len, len-1+a, c));
		len+=a;
	}
	inte pa=0, pb=v.size()-1;
	inte cnt=0;
	while(pa<pb){
		// Calculate their part in common
		inte la=v[pa].l, ra=v[pa].r, 
			revlb=len-1-v[pb].r, revrb=len-1-v[pb].l;
		inte cl = max(la, revlb), cr = min(ra, revrb);
		// Add cnt if they are not the same
		if(v[pa].c!=v[pb].c){
			cnt+=cr-cl+1;
		}
		// Go to next sep
		if(ra==revrb){
			pa++, pb--;
		}else if(ra<revrb){
			pa++;
		}else // ra>revrb
		{
			pb--;
		}
	}
	cout<<cnt;
	return 0;
} 
// something ...
// FengNing X, 786 
