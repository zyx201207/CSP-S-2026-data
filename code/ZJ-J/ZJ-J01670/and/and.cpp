#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
string s[200005];
string ss;
int i;
int t,t2;
int cnt;
string ans;
int ansz;
void ejz(int x){
	if (x == 0) return;
	s[i] += x % 2 +48;
	ejz(x/2);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (i = 1;i <= n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	for (i = n;i >= 1;i--){
		ejz(a[i]); 
		
	}
	t = s[n].size();
	//cout << t;
	for (i = n;i >= 1 ;i--){
		for(int j = s[i].size();j <= t-1;j++)s[i] += 48;
		//cout << s[i] << "  ";
	}
	//cout << endl;
	for (i = t-1;i>=0;i--){
		cnt = 0;
		for (int j = n;j >= 1;j--){
			ss = s[j];
			if (ss[i] == '1')cnt+= 1;
		}
		//cout<< cnt << "cnt"<< endl;
		if  (cnt >= m){
			ans += 49;
			for (int j = n;j >= 1;j--)if(s[j][i] == '0')s[j] = '0';
		}
		else ans += 48;
	}
	t2 = ans.size();
	//cout << t2 << "t2"; 
	for (int i = 0;i <=t2-1;i++){
		if (ans[i] == '1')ansz += pow(2,t2-i-1);
		//cout << ans[i] << endl;
	}
	cout << ansz;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
