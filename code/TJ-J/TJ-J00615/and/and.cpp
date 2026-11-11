#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=200010;
int dig=128;
int a[N];
int n,m;
bool cmp(int a,int b){
	if((a&dig)&&(b&dig))
		return a>b;
	return a&dig;
}
signed main(){
	freopen("and.in","r",stdin);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]==0)
			n--,i--;
	}
	sort(a,a+n);
	if(m>n){
		int Trick=10,Treat=31;
		cout << !(Trick||Treat);//t r ick t r eat
		return !(Trick||Treat);
	}
	int i=0;
	while(dig!=0){
		sort(a,a+n,cmp);
		for(i=0;i<n;i++){
			if(!(a[i]&dig))
				break;
		}
		if(i>=m)
			n=i;
		dig/=2;
	}
	int ans=(1ll<<30)-1;
	for(int i=0;i<m;i++)
		ans&=a[i];
	cout << ans;
} 
