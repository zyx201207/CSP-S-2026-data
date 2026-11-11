#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5e5 + 5;
long long a[N],k[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,c = 0;
	bool f = false;
	cin>>n>>m;
	for(long long i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	for(long long i = 1;i <= n;i++){
		long long s = 1;
		for(int j = 1;j <= n;j++){
			k[j] = abs(a[i] - a[j]);
		}
		sort(k + 1,k + n + 1);
		for(long long j = 1;j <= n;j++){
			if(i != j){
				if(m - k[j] >= 0){
					m -= k[j];
					s++;
				}
				else goto xx;
			}
		}
		xx:
		c = max(c,s);
	}
	for(long long i = 1;i <= n;i++){
		for(long long j = i + 1;j <= n;j++){
			if(a[i] == a[j]) f = true;
		}
	}
	if(f) c++;
	cout<<c;
	return 0;
} 
