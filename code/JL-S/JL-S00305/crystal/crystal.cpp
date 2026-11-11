#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5 * 1e5 + 5;
int n,m;
vector<int> a;
int now = 0;
int tmp;
int first = 0;
int last = 0;
int Arg = 0;
int pos = 0;
int cnt = 0;
int ans = INT_MIN;
int cm;
int fin = INT_MIN;

void solve(){
	while(m != 0){
		int ans = 0;
		int tot = 0;
		//cout << "m>0!\n";
		for(int i = 0;i < n;i++){
			if(a[i] == Arg){
				cnt++;
			}
			tot += (a[n - 1] - a[i]);
		}
		//cout << tot << " " << m << "\n";
		if(tot <= m){
			cout << n;
			return;
		}
		ans = max(ans,cnt);
		for(int i = pos;;i++){
			if(a[i] != Arg){
				Arg = a[i];
				pos = i;
				break;
			}
		}	
		//cout << Arg << " " << pos << "\n";
		for(int i = pos;i >= 0;i--){
			if(Arg - a[i] <= m){
				//cout << a[i] << " ";
				m -= (Arg - a[i]);
				//cout << cm << "\n";
				a[i] = Arg;
			}else{
				break;
			}
		}	
		cnt = 0;
		for(int i = 0;i < n;i++){
			if(a[i] == Arg){
				cnt++;
			}
		}
		fin = max(fin,cnt);
	}
	cout << fin;
	return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    if(m == 0){
		cout << 0;
		return 0;
	}
	if(n == 1){
		cout << 1;
		return 0;
	}
    cm = m;
    bool flag = 0;
    for(int i = 1;i <= n;i++){
		cin >> tmp;
		a.push_back(tmp);
	}
	if(n == 2){
		if(a[1] - a[0] <= m){
			cout << 2;
		}else{
			cout << 1;
		}
		return 0;
	}
	for(int i = 1;i < n;i++){
		if(a[i] - a[i - 1] <= m){
			flag = 1;
			//cout << i << " " << i - 1 << "\n";
			break;
		}
	}
	//cout << flag << " ";
	if(!flag){
		cout << 0;
		return 0;
	}
	sort(a.begin(),a.end());
	if(n % 2 == 1){
		Arg = a[n / 2];
		pos = n / 2 - 1;
	}else{
		Arg = min(a[n / 2],a[n / 2 - 1]);
		pos = n / 2;
	}
	//cout << Arg << " " << pos << "\n";
	solve();

    return 0;
}
