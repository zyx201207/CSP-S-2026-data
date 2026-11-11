#include <bits/stdc++.h>
using namespace std;
long long n,m,last,ans;
long long a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	if(n<=5000){
		for(int i = 1;i<=n;i++){
			cin >> a[i];
		}
		sort(a+1,a+n+1,greater<int>());
		for(int i = 1;i<=n;i++){
			long long cnt=0;last=m;
			for(int j = i;j<=n;j++){
				long long needed = a[i]-a[j];
				if(last>=needed){
					last-=needed;
					cnt++;
				}
			}
//			cout << cnt << '\n';
			ans=max(ans,cnt);
		}
		cout << ans;
	}else{
		int b,c,d;
		cin >> b >> c >> d;
		last=m;
		if(abs(b-c)==1 and abs(d-c)==1){
			for(int i = 1;i<=n;i++){
				if(last<i)break;
				last-=i;
				ans++;
			}
			cout << ans+1;
		}else if(abs(b-c)==abs(d-c)){
			int cnt = abs(b-c); 
			for(int i = 1;i<=n;i++){
				if(last<i*cnt)break;
				last-=i*cnt;
				ans++;
			}
			cout << ans+1;
		}else{
			a[1]=b,a[2]=c,a[3]=d;
			for(int i = 4;i<=n;i++){
				cin >> a[i];
			}
			sort(a+1,a+n+1,greater<int>());
			for(int i = 1;i<=n;i++){
				long long cnt=0;last=m;
				for(int j = i;j<=n;j++){
					long long needed = a[i]-a[j];
					if(last>=needed){
						last-=needed;
						cnt++;
					}
				}
	//			cout << cnt << '\n';
				ans=max(ans,cnt);
			}
			cout << ans;
		}
		
	}
	
	return 0;
} 
