#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long ans[300005];
long long s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(long long i = 1;i <= n;i++) cin >> a[i];
	for(long long i = 1;i <= n;i++){
		memset(s,0,sizeof(s));
		long long tail = 1;
		bool number[300005] = {0};
		for(long long j = i;j <= n;j++){
//			cout << number[3] << endl;
			if(number[a[j]] == 0){
				s[tail] = a[j];
				tail++;
				number[a[j]] = 1;
			}
			else{
				int cur = tail;
				for(long long k = 1;k < tail;k++)
					if(s[k] == a[j]) tail = k + 1;
				for(long long k = tail;k < cur;k++) number[s[k]] = 0;
			}
//			cout << "tail = " << tail << endl;
//			for(int k = 1;k < tail;k++) cout << s[k] << endl;
//			cout << endl;
		}
		while(tail > 1){
			ans[s[--tail]]++;
		}
	}
	for(long long i = 1;i <= m;i++) cout << ans[i] << ' ';
	return 0;
}