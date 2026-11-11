#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int ans;
int n,m,x;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if (m == n){
    	for (int i = 1;i <= n;i++){
    		cin >> x;
			if (i == 1)    ans = x;
			else    ans &= x; 
		}
	}else if (m == 1){
		ans = -1;
		for (int i = 1;i <= n;i++){
			cin >> x;
			ans = max(ans,x);
		} 
    }else if (m == 2){
    	ans = -1;
    	vector<int> a;
    	for (int i = 1;i <= n;i++){
    		cin >> x;
    		a.push_back(x);
		}
		for (int i = 0;i < n-1;i++)
			for (int j = i+1;j < n;j++)
				ans = max(ans,a[i] & a[j]);
	}
	cout << ans << endl;
}  
