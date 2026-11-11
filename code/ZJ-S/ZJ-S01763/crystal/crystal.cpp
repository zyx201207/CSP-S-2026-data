#include<iostream> 
#include<algorithm> 
using namespace std; 
long long a[500005],s[500005]; 
int main() 
{ 
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 
	long long n,m; 
	cin >> n >> m; 
	for(int i = 1;i <= n;i++) cin >> a[i]; 
	sort(a + 1,a + n + 1); 
	for(int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i]; 
	long long sum = 0,j = 1,ans = 0; 
	for(int i = 1;i <= n;i++) 
	{ 
		sum = (i - j + 1) * a[i] - (s[i] - s[j - 1]); 
		while(j <= i && sum > m) 
		{
			j++;
			sum = (i - j + 1) * a[i] - (s[i] - s[j - 1]);
		}
		ans = max(ans,i - j + 1);
	}
	cout << ans << "\n";
	return 0;
}