#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 10;
ll n, l[maxn], ans, ed;
char a[maxn];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin>>n;
	ed = n;
	for(int i = 1;i <= n;i++)
		cin>>l[i]>>a[i];
	int i = 1;
	while(i <= n){
		if(l[i] != 0){
			int c = min(l[i], l[ed]);
			if(a[i] != a[ed])
				ans += c;
			l[i] -= c;
			l[ed] -= c;
			if(l[ed] <= 0)
				ed--;
			if(l[i] <= 0){
				i++;
			}				
		}
		else
			i++;
	}
	cout<<ans<<"\n";
	return 0;
}
//?!³¤³¤!? 
//CCF = Chinese Can FLY!!! = CPL Can FLY!!!!!!!
