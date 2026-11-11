#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e5+10;
int n,cnt;
struct Node{
	char c;
	int num;
}a[N],b[N];

signed main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin >> n;
	for (int i=1;i<=n;i++){
		cin >> a[i].num >> a[i].c;
		cnt+=a[i].num;
	}
	for (int i=1;i<=n;i++){
		b[i].num=a[n+1-i].num;
		b[i].c=a[n+1-i].c;
	}
	int posa=1,posb=1;
	int ans=0;
	while (cnt){
		if (a[posa].c==b[posb].c){
			if (a[posa].num>b[posb].num){
				cnt-=b[posb].num;
				a[posa].num-=b[posb].num;
				posb++;
			}
			else if (a[posa].num<b[posb].num){
				cnt-=a[posa].num;
				b[posb].num-=a[posa].num;
				posa++;
			}
			else{
				cnt-=a[posa].num;
				posa++;
				posb++;
			}
		}
		else{
			if (a[posa].num>b[posb].num){
				ans+=b[posb].num;
				cnt-=b[posb].num;
				a[posa].num-=b[posb].num;
				posb++;
			}
			else if (a[posa].num<b[posb].num){
				ans+=a[posa].num;
				cnt-=a[posa].num;
				b[posb].num-=a[posa].num;
				posa++;
			}
			else{
				ans+=a[posa].num;
				cnt-=a[posa].num;
				posa++;
				posb++;
			}
		}
	}
	cout << ans/2;
	return 0;
}
