#include<bits/stdc++.h>
#define pb emplace_back
//#define int long long
using namespace std;
const int N=2e5+10;
int n,m,ans;
vector<int> v,t;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		v.pb(x);
	}
	for(int j=29;j>=0;j--){
		int cnt=0;
		for(int i=0;i<v.size();i++){
			cnt+=((v[i]>>j)&1);
		}
//		cout<<cnt<<endl;
		if(cnt<m){
			continue;
		}
//		for(auto i:v){
//			cout<<i<<" ";
//		}
//		cout<<endl<<"==="<<endl;
		ans+=(1<<j);
		t.clear();
		for(int i=0;i<v.size();i++){
			if((v[i]>>j)&1){
				t.pb(v[i]);
			}
		}
		v=t;
	}
	cout<<ans<<endl;
	return 0;
}
/*
ok this problem is more more more easier than T2 you know lol

solve the i-th position(in binary),if there are k numbers have 2^i:
if k>m:keep these answer,the final answer can only be chose in these numbers 
if k<m:this positon must cannot influence answer,we mustn't caculate them

why it is correct:to small from big is the best,prove it is easy so i don't prove lol

score 100 pts
time 7 min
difficulty 2
even less than T1 lol
*/