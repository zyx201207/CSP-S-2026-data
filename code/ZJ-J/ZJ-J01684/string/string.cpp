#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
char c[N];
int cnt[50];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	int sum = 0;
	for(int i=1;i<=n;++i){
		cin >> a[i] >> c[i];sum+=a[i];
		cnt[c[i]-'a']++;
		for(int j=1;j<=a[i];++j){
			s+=c[i];
		}
	}
	int k=0;
	for(int i=0;i<=30;++i){
		if(cnt[i]) ++k;
	}
	if(k == 1){
		cout << 0;
		return 0;
	}
	
	if(sum == 1){
		cout << 0;
		return 0;
	}
	if(sum == 2){
		cout <<1;
		return 0;
	}
	if(sum&1){
		int op = sum/2+1;
		int i=op-1;
		int j=op+1;
		int ans = 0;
		while(i>=0&&j<=s.size()){
			if(s[i] != s[j]){
				ans++;
			}
			--i;
			++j;
		}
		cout << ans;
	}else{
		int i=sum/2;
		int j=sum/2+1;
		int ans = 0;
		while(i>=0&&j<=s.size()){
			if(s[i] != s[j]){
				ans++;
			}
			--i;
			++j;
		}
		cout << ans;
	}
	return 0;
}
