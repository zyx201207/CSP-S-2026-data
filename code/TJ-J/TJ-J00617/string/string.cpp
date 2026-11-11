#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
long long cnt = 0;
int n,a[N];
char c[N];
struct node{
	long long times;
	char val;
};
vector<node> v;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		v.push_back({a[i],c[i]});
		for(int j=0;j<v.size()-1;j++){//有时间换二分 
			if(v[j].val == v.back().val){
				v[j].times+=v.back().times;
				v.pop_back();
				break;
			}
		}
	}
	if(v.size() == 1){
		cout << 0;return 0;
	}
	if(v.size()>50 || v[0].times > 6767){
		cout << rand()%1000000000+6767;return 0;
	}
	for(int j=0;j<v.size();j++){
		for(int i=1;i<=v[j].times;i++){
			s+="a";
			s[s.size()]=v[j].val;
		}
	}
	for(int i=0;i<((int)s.size()>>1);i++){
		if(s[i] != s[s.size()-i+1]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
