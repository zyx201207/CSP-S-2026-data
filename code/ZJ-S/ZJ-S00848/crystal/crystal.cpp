#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
    	cin >> a[i];
	}
	sort(a+1,a+n+1);
	bool dc = 1;
	int c = a[2]-a[1];
	for(int i = 3;i<=n;i++){
    	int x = a[i]-a[i-1];
    	if(x!=c){
    		dc = 0;
		}
	}
	if(dc){
		int ans = 1;
		int bs = 0;
		while(m>0){
			bs++;
			if(bs>=n) break;
			int dj = bs*c;
			if(m>=dj){
				ans++;
			}
			m-=dj;
		}
		if(m>0){
			if(m%n==0){
				cout << n;
			}else{
				cout << m%n;
			}
		}else{
			cout << ans;
		}
		return 0;
	}
	int ans = 1;
	for(int i = 2;i<=n;i++){
		int nl = m;
		int dsum = 1;
		int l = i-1;
		int sx = i;
		while(nl>0&&l>=1){
		//	cout << i << " " << l << " " << dsum << " " << nl <<" "<< a[i]-a[l] <<"\n";
			if(dsum>=sx) break;
			int dj = a[i]-a[l];
			if(nl>=dj){
				dsum++;
			}
			nl-=dj;
			l--;
		//	cout << i << " " << l << " " << dsum << " " << nl << "\n";
		}
		if(nl>0){
			if(nl%sx==0){
				ans = max(ans,sx);
			}else{
				ans = max(ans,nl%sx);
			}
		}else{
			ans = max(ans,dsum);
		}
	}
	cout << ans;
	return 0;
}
