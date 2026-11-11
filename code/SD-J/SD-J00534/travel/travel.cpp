#include <bits/stdc++.h>

#define PII pair <int,int>
#define fi first
#define se second
#define all(u) (u).begin(),(u).end()
#define lb lower_bound
#define ub upper_bound
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define ll long long
#define N 1000005

using namespace std;
string s_1,t_1,s_2,t_2;
map <pair <char,char>,bool> M;
signed main() {
	freopen("travel.in","r",stdin);
//	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	M[{'A','B'}] = M[{'B','C'}] = M[{'D','F'}] = 1;
	cin>>s_1>>t_1>>s_2>>t_2;
	int x = (t_1[0] - '0') * 10 + t_1[1],y = (t_2[0] - '0') * 10 + t_2[1];
	cout<<(s_1 == s_2);
	bool p = (s_1 == s_2 && x == y);
	bool q = p && !((t_1[2] < 'D') ^ (t_2[2] < 'D'));
	cout<<p<<q<<(q && (M[{t_1[2],t_2[2]}] || M[{t_2[2],t_1[2]}]))<<"\n";
	return 0;
}
