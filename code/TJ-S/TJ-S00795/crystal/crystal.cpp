#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
long long a[500005],m,s[500005],n;
long long minn = 2e12;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
    for(int i = 1;i<=n;i++){
    	cin >> a[i];
    	minn = min(minn,a[i]);
	}
	sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
    	s[i] = s[i-1]+a[i];
	}
	int maxx = 0,i = 1;
	for(;i<=n;i++){
		if(a[i]*i-s[i] > m){
			break;
		}
	}
	cout << i-1;
    return 0;
}
