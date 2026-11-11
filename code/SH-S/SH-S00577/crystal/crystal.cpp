#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
int q_l = 1 , q_r = 0;
void init(int n)
{
	a.assign(n + 1,0);
	q_l = 1;
	q_r = 1;
}

inline int len()
{
	return q_r - q_l + 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    long long n,m;
    cin >> n >> m;
    init(n);
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a.begin() + 1,a.end());
    
    
    int max_len = 1;
    long long k = 0;
    
    for(int i = 2;i <= n;i++)
    {
    	k += (a[i] - a[i - 1]) * len();
    	q_r++;
    	while(len() > 0 && k > m) k -= a[i] - a[q_l++];
    	
    	max_len = max(max_len,len());
	}
    
    cout << max_len;
    return 0;
}
