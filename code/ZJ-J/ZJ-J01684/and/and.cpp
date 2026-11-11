#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int p[N][50];
int a[N];
struct D{
	int cnt,sum;
}tot[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin >> n >>k;
	for(int i=1;i<=31;++i) tot[i].sum=(1<<31)-1;
	for(int i=1;i<=n;++i){
	    cin >> a[i];
	    
	}
	sort(a+1,a+n+1,greater<int>());
  /*  for(int i=1;i<=n;++i){
		int x = a[i];
	    int j=1;
	    while(x){
	    	int k = x%2;
	    	p[i][j] = k;
	    	x/=2;
	    	++j;
	    	
		}
	}for(int i=1;i<=n;++i){
		for(int j=1;j<=31;++j){
			cout << p[i][j] << " " ;
		}
		cout << "\n";
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=31;++j){
		    if(p[i][j]){
		    	tot[j].cnt++;
		    	tot[j].sum&=a[i];
			}
		}
	}int ans = ((1<<31)-1);
	for(int i=31;i>=1;--i){
		if(tot[i].cnt == k){
			ans &= tot[i].sum;
		}
	}

cout<<ans;
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=31;++j){
		    if(tot[j]<k){
			    p[i][j] = 0;
		    }
		}
	}
	sort(a+1,a+n+1,greater<int>());*/
	
	
	
    int ans = ((1<<31)-1);
    for(int i=1;i<=k;++i){
    	ans &= a[i];
    	
	}
	if(ans == 0){
		
		cout<<a[2];
		return 0;
	}else{
		cout << ans;
		return 0;
	}
	sort(a+1,a+n+1,greater<int>());
	int ans1 = ((1<<31)-1);
    for(int i=1;i<=k;++i){
    	ans1 &= a[i];
    	
	}
	
	cout << ans1;
	return 0;
}
