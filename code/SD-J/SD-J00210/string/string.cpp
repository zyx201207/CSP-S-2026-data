#include<bits/stdc++.h>
#define int long long
int cnt[200010];
char ch[200010];
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt1=0,cnt2=0;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		cnt1+=a;
		cnt[i]=cnt1;
		ch[i]=c;
	}
	for(int i=1;i<=cnt1/2;i++){
		int l=1,r=n,ans1=n+1;
		while(l<=r){
			int mid=(l+r)/2;
			if(cnt[mid]>=i){
				ans1=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
			cout<<1;
		}
		l=1;
		r=n;
		int ans2=n+1;
		while(l<=r){
			int mid=(l+r)/2;
			if(cnt[mid]>=cnt1-i+1){
				ans2=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
			cout<<2;
		}
		if(ch[ans1]!=ch[ans2]){
			cnt2++;
		}
	}
	cout<<cnt2;
	return 0;
}
