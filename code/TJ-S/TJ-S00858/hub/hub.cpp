#include <bits/stdc++.h>
using namespace std;
long long a[500005] = {};
long long xtsl[500005] = {};
long long czcs[500005] = {};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long m,n;
	cin>>n>>m;
	 for(long long i = 1; i <= n; i++){
	 	cin>>a[i];
	}
	sort(a + 1,a + n + 1);
	
	for(long long i = 1; i <= n; i++){
		xtsl[i] = 1,czcs[i] = 0;
		for(long long j = 1; j <= n; j++){
			if(a[i] != a[j]){
				czcs[i] += abs(a[j] - a[i]);
				if(czcs[i] <= m){
					xtsl[i]++;
				}else{
					break;
				}
			}
		}
	}
	sort(xtsl + 1,xtsl + n+ 1);
	cout<<xtsl[n];
	return 0;
}
