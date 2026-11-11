//crystal
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans=-2e9;
signed main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	/**/
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a,a+1+n);
	int l=1,r=1,cnt=0;
	while(l<=r && r<=n){
		if(cnt <= m){
			ans=max(ans,r-l+1);
			/*
			if(r-l+1 == 315276){
				cout << "#####\n";
				for(int i=l;i<=r;i++){
					cout << a[i] << ' ';
				} 
				cout << "\n#####\n";
			} */
			//cout << "###" << l <<' ' << r  << ' ' << cnt << "###\n";
			r++;
			cnt += (a[r]-a[r-1])*(r-l);
		}else{
			cnt -= a[r]-a[l];
			l++;
			
		}
	}
	cout << ans;
	return 0;
	
} 
/*

2

  |   |
1 2 4 8 9
3 2 0
*/
