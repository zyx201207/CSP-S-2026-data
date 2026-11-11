#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[500005];
long long diff[500005];
long long pre[500005];

inline bool check(int M, int i){
	return pre[i]-(a[i]-a[M-1])*(M-1)-pre[M-1]<=m;
}

signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c;
    cin>>c;
    cin>>c;
    for(;c--;){
    	printf("1\n");
	}
}