#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,cnt=0;
struct node{
	int x;
	char c;
}a[N],b[N];
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cnt=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	for(int i=1;i<=n;i++){
		if(a[i].c==b[cnt].c){
			b[cnt].x+=a[i].x;
		}else{
			b[++cnt].x=a[i].x;
			b[cnt].c=a[i].c;
		}
	}
	for(int l=1,r=cnt;l<r;l++,r--){
		if(b[l].c!=b[r].c){
			if(b[l].x<b[r].x){
				ans+=b[l].x;
				b[l].c=b[r].c;
			}else{
				ans+=b[r].x;
				b[r].c=b[l].c;
			}
		}
		int c=abs(b[r].x-b[l].x);
		if(b[l].x<b[r].x){
			b[l+1].x-=c;
		}else if(b[l].x>b[r].x){
			b[r-1].x-=c;
		}
		ans+=c;
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
