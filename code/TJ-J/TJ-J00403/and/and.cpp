#include<bits/stdc++.h>
#define int long long
using namespace std;
string s[200010];
bool cmp(string s1,string s2){
	return s1>s2;
}
int sum=0;
int maxx=0;
string cl[200010];
int cnt;
int n,m;
int pl=0;
int jm=1;
void check(int ol){
	sort(cl+1,cl+cnt+1,cmp);
	for (int i=maxx-1;i>=ol;i--){
		pl=0;
		for (int j=1;j<=m;j++){
			if (cl[j][i]=='0'){
				pl=1;
				break;
			}
		}
		if (pl==0){
			sum=sum+jm;
		}
		jm*=2;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int len=0;
	string t="";
	int mx=0;
	int x;
	for (int i=1;i<=n;i++){
		cin >> x;
		mx=max(mx,x);
		t="";
		while (x!=0){
			t=t+char(x%2+'0');
			x/=2;
		}
		s[i]=t;
		len=t.size();
		maxx=max(maxx,len);
	}
	if (m==1){
		cout << mx;
		return 0;
	}
	for (int i=1;i<=n;i++){
		while (s[i].size()<maxx){
			s[i]+='0';
		}
		reverse(s[i].begin(),s[i].end());
	}
	sort(s+1,s+n+1,cmp);
	int fg=0;
	for (int i=0;i<maxx;i++){
		cnt=0;
		for (int j=1;j<=n;j++){
			if (s[j][i]=='1'){
				cl[++cnt]=s[j];
			}
		}
		if (cnt>=m){
			check(i);
			break;
		}
	}
	cout << sum;
	return 0;
}
