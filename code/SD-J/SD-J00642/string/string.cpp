#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+10;
int n,m,q;
int ans=0;
char op[N];
int num[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>num[i]>>op[i];
	}
	int l=1,r=n;
	while(l<r){
		int cz=min(num[l],num[r]);
		if(op[l]!=op[r]){
			ans+=cz;
		}
		num[l]-=cz;
		num[r]-=cz;
		if(num[l]==0) l++;
		if(num[r]==0) r--;
	}
	cout <<ans;
	return 0;
}
