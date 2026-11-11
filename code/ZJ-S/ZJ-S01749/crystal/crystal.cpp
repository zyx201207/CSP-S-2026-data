#include<bits/stdc++.h>//shuang zhi zhen or er fen?
#define int long long
using namespace std;
int n,m,arr[514514];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>arr[i];
	sort(arr,arr+n);
	int left=1,right=1,tot=0,ans=1;
	for(;;){
		left++;
		if(left>n)break;
		tot+=1ll*(left-right)*(arr[left]-arr[left-1]);
		while(tot>m&&right<left){
			tot-=(arr[left]-arr[right]);
			right++;
		}
		ans=max(ans,left-right+1);
	}
	cout<<ans;
	return 0;
}
/*www.luogu.com.cn/user/747611
mi huo xing wei da shang QwQ

Generals.io FFA 30~40

shang shan ruo shui,ren jie di ling.
Halloween==Christmas?
//freopen();

Igallta AT 17.4
[[] ---     []]
[[]     --- []]
[[] ---     []]
[[]     --- []]
[[] ---     []]
[[]     --- []]
[[] ---     []]
[[]     --- []]
[[] ---     []]
[[]     --- []]
[[]         []]
*/
