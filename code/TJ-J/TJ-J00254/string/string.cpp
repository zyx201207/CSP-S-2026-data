#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200010];
char c[200010];
struct node{
	int len;
	char x;
}s[200010];
int cnt;
int ans;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i]+=a[i-1];
			a[i-1]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			s[++cnt].len=a[i];
			s[cnt].x=c[i];
		}
	}
	int l=1,r=cnt;
	while(l<=r){
		if(s[l].x!=s[r].x){
			if(s[l].len>s[r].len){
				ans+=s[r].len;
				s[l].len-=s[r].len;
				s[r].len=0;
				r--;
			}
			else if(s[l].len==s[r].len){
				ans+=s[r].len;
				s[r].len=0;
				s[l].len=0;
				l++,r--;
			}
			else{
				ans+=s[l].len;
				s[r].len-=s[l].len;
				s[l].len=0;
				l++;
			}
		}
		else if(s[l].x==s[r].x){
			if(s[l].len>s[r].len){
				s[l].len-=s[r].len;
				r--;
			}
			else if(s[l].len==s[r].len){
				l++;
				r--;
			}
			else{
				s[r].len-=s[l].len;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
