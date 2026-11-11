#include<bits/stdc++.h>

using namespace std;
long long n,m1,a[500010],cnt[300010],s[300010],o[300010],m[500010];
int main(){
	freopen("r","card.in",stdin);
	freopen("w","card.out",stdout); 
	cin >> n >> m1;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(long long i = 1; i <= n; i++){
		memset(o,0,sizeof(o));
		memset(m,0,sizeof(m));
		memset(s,0,sizeof(s));
		long long l = i;
		for(long long j = i; j <= n; j++){
			if(o[a[j]] == 1){
				l = s[a[j]];
			}else{
				s[a[j]] = j;
				o[a[j]] = 1;
				if(o[a[j - 1]] == 1){
					m[++l] = a[j];
				}else{
					m[l++] = a[j];
				}
			}
			for(long long k = 1; k <= m1; k++){
				if(s[a[j]] > l){
					o[a[j]] = 0;
					s[a[j]] = 0;
				}
			}
		}
		for(long long j = i; j <= l; j++){
			cnt[m[j]]++;
		}
	}
	for(long long i = 1; i <= m1; i++){
		cout << cnt[i] << ' ';
	}
	return 0;
}
