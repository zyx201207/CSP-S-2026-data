#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,l=1,r;
long long num[N],cnt;
char cha[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++) cin>>num[i]>>cha[i];
	while(l<r){
		long long mid=min(num[l],num[r]);
		if(cha[l]!=cha[r]) cnt+=mid;
		num[l]-=mid;
		num[r]-=mid;
		if(!num[l]) l++;
		if(!num[r]) r--;
	}
	cout<<cnt;
	return 0;
}
