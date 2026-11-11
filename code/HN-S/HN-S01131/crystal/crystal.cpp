#include<bits/stdc++.h>
using namespace std;
#define N 5000010
int a[N],b[N],z[N],lt[N],num = 0,ans[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n,x = 0;
	cin>>n>>m;
	for(int i = 0;i < n;i++) cin>>a[i];
	sort(a,a+n);
	z[num] = a[0];
	for(int i = 1 ;i < n;i++){
		if(a[i] == a[i-1]) b[num]++;
		else {
			z[++num] = a[i];
			b[num] = 1;
			lt[num] = i;
		}
	}
	
	ans[0] = b[0];
	for(int i = 1;i <= num;i++){
		for(int j = lt[i]-1;j >= 0;j--){
			int x = m;
			x = x + a[j] - z[i];
			if(x < 0) break;
			else ans[i]++;
		}
		ans[i]+=b[i];
	}
	sort(ans,ans+num+1);
	cout<<ans[num];
	return 0;
}
