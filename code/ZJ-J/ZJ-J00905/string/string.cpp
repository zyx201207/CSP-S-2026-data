#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e5+5;
int n;
int cnt[N];
char a[N];

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int answer=0;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>a[i];
		answer+=cnt[i];
	}
	int l=1,r=answer;
	int l1=1,r1=n;
	int x_l1=cnt[l1],x_r1=answer-cnt[r1];
	int ans=0;
	while(l<=r){
		if(l>x_l1){
			l1++;
			x_l1+=cnt[l1];
		}
		if(r<=x_r1){
			r1--;
			x_r1-=cnt[r1];
		}
		if(a[l1]!=a[r1]){
			ans++;
		}
		l++,r--;
	}
	cout<<ans;
	return 0;
}
