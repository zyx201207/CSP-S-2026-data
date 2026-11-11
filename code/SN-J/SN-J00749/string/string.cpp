#include<bits/stdc++.h>
using namespace std;
int n;
int len[200010];
char c[200010];
long long sum;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++) {
		cin>>len[i]>>c[i];
	}
	int ll = 1,rr = n;
	while(ll <= rr) {
		if(ll == rr) {
			break;
		}
		if(len[ll] > len[rr]) {
			len[ll]-=len[rr];
			if(c[ll] != c[rr]) {
				sum+=len[rr];
			}
			len[rr] = 0;
			rr--;
		} else if(len[rr] > len[ll]) {
			len[rr]-=len[ll];
			if(c[rr] != c[ll]) {
				sum+=len[ll];
			}
			len[ll] = 0;
			ll++;
		} else {
			if(c[ll] != c[rr])  {
				sum+=len[ll];
			}
			len[ll] = 0;
			len[rr] = 0;
			ll++;
			rr--;
		}
	}
	cout<<sum; 
	return 0;
}
