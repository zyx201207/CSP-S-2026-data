#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 500005;
ll Arr[N], Pre[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n;ll m;	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>Arr[i];
	sort(Arr+1, Arr+1+n);
	for(int i=1;i<=n;i++)	Pre[i]=Pre[i-1]+Arr[i];
	
	int Ans=0;
	for(int i=1;i<=n;i++) {
		int l=1, r=i;
		for(int Mid=(l+r)/2;l<r;Mid=(l+r)/2)
			Arr[i]*(i-Mid+1)-(Pre[i]-Pre[Mid-1])>m? l=Mid+1:r=Mid;
		Ans=max(Ans, i-l+1);
	}
	cout<<Ans<<endl;
	return 0;
}
