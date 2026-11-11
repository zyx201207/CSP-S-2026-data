#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int cnt;
	char ch;
}a[200005],b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].ch;
		b[i].cnt=a[i].cnt;
		b[i].ch=a[i].ch;
	}
	int l=1,r=n;
	while(l<r){
		if(b[l].ch!=b[r].ch){
			if(b[l].cnt>b[r].cnt){
				ans+=b[r].cnt;
				b[l].cnt-=b[r].cnt;
				b[r].cnt=0;
			}
			else{
				ans+=b[l].cnt;
				b[r].cnt-=b[l].cnt;
				b[l].cnt=0;
			}
		}
		else{
			if(b[l].cnt>b[r].cnt){
				b[l].cnt-=b[r].cnt;
				b[r].cnt=0;
			}
			else{
				b[r].cnt-=b[l].cnt;
				b[l].cnt=0;
			}
		}
		if(b[l].cnt==0) l++;
		if(b[r].cnt==0) r--;
	}
	cout<<ans;
	return 0;
}
