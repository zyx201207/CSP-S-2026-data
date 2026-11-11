#include<bits/stdc++.h>
using namespace std;
#define int long long
struct sf{
	int sh;
	char a;
};
const int maxn=2e5+5;
sf a[maxn];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%lld %c", &a[i].sh, &a[i].a);
	}
	int ans=0;
	for(int i=1, j=n;i<j;){
		if(a[i].sh>a[j].sh){
			a[i].sh-=a[j].sh;
			if(a[i].a!=a[j].a){
				ans+=a[j].sh;
			}
			j--;
		}
		else{
			a[j].sh-=a[i].sh;
			if(a[i].a!=a[j].a){
				ans+=a[i].sh;
			}
			i++;
		}
	}
	cout << ans;
	return 0;
} 
