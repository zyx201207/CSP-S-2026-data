#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1919810],n,m,pfs[1919810];
bool check(int x){
    ll dis = 0;
    for (ll R = x;R <= n;R++){
		ll L = R-x+1;
		ll sum = pfs[R] - pfs[L-1];
		dis = a[R]*x - sum;
        if (dis <= m)return 1;
    }
    return 0;
}
int main(){
    pfs[0] = 0;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (ll i = 1;i <= n;i++){
        cin >>a[i];
    }
    sort(a+1,a+n+1);
    for (ll i = 1;i <= n;i++)pfs[i] = pfs[i-1] + a[i];
    ll L = 1,R = n;
    ll mid = (L+R) >>1,ans = -1;
    while (L <= R){
        mid = (L+R) >>1;
        if (check(mid)){
            ans = mid;L = mid+1;
        }
        else R = mid-1;
    }
    cout << ans;return 0;
}
//myd nb
//VAMOS DALIAN

// How time flies.


/*
 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1919810],n,m;
ll C[1919810];
ll mymax(ll a,ll b){
	if (a > b)return a;
	return b;
}
int get_root(int m){
	int L = 1,R = m;int ans = -1;
	int mid = (L+R) >> 1;
	while (L <= R){
		mid=  (L+R) / 2;
		if (mid * mid+mid <= m && (mid+1)*(mid+1)+mid+1 >m){
			ans = mid;return ans;
		}
		if (mid*mid+mid> m){
			R = mid-1;
		}
		if (mid*mid+mid<m){
			L = mid+1;
		}
	}
	return ans;
}
void subtask1(){
	for (int i = 1;i <= n;i++)C[a[i]]++;
	int ans = INT_MIN;
	for (int i = 2;i <= n;i++){
		int M = m,Std = a[i],cnt = 0;
		for (int j = i-1;j >= 1;j--){
			if (M  >= Std- a[j]){
				M -= (Std-a[j]);
				cnt++;
			}
			else break;
		}
		cnt += C[a[i]];
		ans = mymax(ans,cnt);
	}
	cout << ans;
}
void A(){
	int gc = a[2] - a[1];
	int N = get_root(2*m / gc);
	if (N*N+N == m*2/gc)N++;
	cout <<  min(n,N+1);
}
signed main(){
	freopen("TRY2.in","r",stdin);
	memset(C,0,sizeof C);
	cin >> n >> m;
	bool isA = 1,isB = 1;int gc;
	for (int i = 1;i <= n;i++){
		cin >> a[i];  
	}
	sort(a+1,a+n+1);
	if (n <= 5001){
		subtask1();
		return 0;
	}
	gc = a[2]-a[1];
	for (int i = 3;i <= n;i++){
		if (a[i] - a[i-1] != gc){
			isA = 0;
		}
	}
	if (isA){
		A();return 0;
	}
	
}
*/
