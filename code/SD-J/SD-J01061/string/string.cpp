#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int cnt;
	char data;
}a[100010];
int pre[100010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].data;
		pre[i]=pre[i-1]+a[i].cnt;
		cnt+=a[i].cnt;
	}
	int cnt_1=0,fl=0,ans=0;
	for(int i=1;i<=n;i++){
		if(cnt_1>(cnt+1)/2){
			cnt_1-=(cnt+1)/2;
			fl=1;
		}
		if(fl){
			int id=lower_bound(pre+1,pre+n+1,(cnt+1)/2-cnt_1)-pre;
			if(a[i].data!=a[id].data) ans+=abs(pre[id]-cnt_1);
		}
		cnt_1+=a[i].cnt;
		if(cnt_1>(cnt+1)/2){
			cnt_1-=(cnt+1)/2;
			fl=1;
		}
		if(fl){
			int id=lower_bound(pre+1,pre+n+1,(cnt+1)/2-cnt_1)-pre;
			if(a[i].data!=a[id].data)m ans+=abs(pre[id]-cnt_1);
		}
	} 
	cout<<ans;
    return 0;
}
