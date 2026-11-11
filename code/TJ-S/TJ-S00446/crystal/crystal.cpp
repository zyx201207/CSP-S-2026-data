#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,num[500005],ans = 0,t[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool ch = 1;
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>num[i];
	}
	sort(num + 1,num + n + 1);
	long long a = num[2] - num[1];
	for(int i = 2;i <= n;i++){
		if((num[i] - num[i - 1]) != a) ch = 0;
	}
	
	if(n <= 5000){
		for(long long i = 1;i <= n;i++){
			long long cnt = m;
			for(long long j = i - 1;j >= 1;j--){
				long long x = num[i] - num[j];
				if(cnt < x) break;
				cnt -= x;
				ans = max(ans,(i - j + 1));
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(ch){
		long long cnt = 0;
		long long x = num[2] - num[1];
		for(int i = 1;i <= n;i += x){
			cnt += i;
			if(cnt == m){
				cout<<i + 1<<endl;
				return 0;
			}
			if(cnt > m){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	cout<<(1ll + n) / 2ll;
	return 0;
}

