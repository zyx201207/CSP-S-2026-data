#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
struct node {
	int num;
	char c;
} arr[200005];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>arr[i].num>>arr[i].c;
		if(arr[i].c==arr[i-1].c) {
			n--;
			arr[i-1].num+=arr[i].num;
			i--;
		}
	}

	int lst=1,rst=n;
	while(lst<rst) { //O(n)
		if(arr[lst].c==arr[rst].c) {
			int mn=min(arr[lst].num,arr[rst].num);
			arr[lst].num-=mn,arr[rst].num-=mn;
			if(arr[lst].num==0)lst++;
			if(arr[rst].num==0)rst--;
		} else break;
	}

	while(lst<=rst) {
		if(lst==rst)break;
		if(arr[lst].c!=arr[rst].c) {
			if(arr[lst].num==arr[rst].num) {
				ans+=arr[lst].num;
				lst++,rst--;
			} else if(arr[lst].num>arr[rst].num) {
				arr[lst].num-=arr[rst].num;
				ans+=arr[rst].num;
				rst--;
			} else {
				arr[rst].num-=arr[lst].num;
				ans+=arr[lst].num;
				lst++;
			}
		}else{
			int mn=min(arr[lst].num,arr[rst].num);
			arr[lst].num-=mn,arr[rst].num-=mn;
			if(arr[lst].num==0)lst++;
			if(arr[rst].num==0)rst--;
		}
	}
	cout<<ans;
	return 0;
}
