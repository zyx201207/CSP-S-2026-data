#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,cnt=0,ok=1; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	if(n == 1){
		cout << 1;
	}else{
		long long bz = a[2]-a[1];
		for(int i = 3;i <= n;i++){
			if(a[i] - a[i-1] != bz){
				ok = 0;
			}
		}
		if(ok == 1){
			for(int i = 1;i <= n;i++){
				if(cnt + i*bz > m){
					break;
				}
				cnt += i*bz;
				ans++;
			}
			cout << ans;
		}else{
			long long mm = m;
			for(int i = 2;i <= n;i++){
				cnt = 1;
				m = mm;
				for(int j = i-1;j >= 1;j--){
					if(a[i]-a[j] <= m){
						cnt++;
						m -= (a[i]-a[j]);
					}else{
						break;
					} 
				}
				ans = max(ans,cnt);
			}
			cout << ans;
		}
	}
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
