#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int a[10005];
    for(int i = 1;i <= n;i++){
    	cin >> a[i];
	}
	sort(a+1,a+n+1);//1 2 4 8 9
	
	while(m > 0){
		a[1]++;
		m--;
		sort(a+1,a+n+1);//22489 32489 33489 43489 44489
	}
	sort(a+1,a+n+1);
	a[0] = 0;
	int cnt = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == a[i-1]){
			cnt++;
		}
	}
	if(cnt > 0){
		cout << cnt + 1;
	}
	return 0;
}
