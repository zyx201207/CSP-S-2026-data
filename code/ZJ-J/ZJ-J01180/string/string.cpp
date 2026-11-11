#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,cnt1,cnt2,l;
struct node{ll len;char c;}a[N];
struct Node{ll len;char c;}b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		if(a[i].c==a[i-1].c){
			b[cnt].len+=a[i].len;
			b[cnt].c=a[i].c;
		}
		else{
			cnt++;
			b[cnt].len=a[i].len;
			b[cnt].c=a[i].c;
		}
		l+=a[i].len;
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	if(cnt==2){
		cout<<min(b[1].len,b[2].len);
		return 0;
	}
	ll pre=0,nxt=0;
	for(int i=1;i<=n;i++){
		if(pre>=l/2||nxt>=l/2)break;
		if(b[i].c!=b[n-i+1].c){
			if(b[i].len>=b[n-i+1].len){
				pre+=b[i].len;
				nxt+=b[i].len;
				b[n-i].len-=abs(b[n-i+1].len-b[i].len);
				cnt1+=b[i].len;
			}
			else{
				pre+=b[i].len;
				nxt+=b[i].len;
				b[n-i].len+=abs(b[n-i+1].len-b[i].len);
				cnt1+=b[n-i+1].len;
			}
		}
		if(b[i].c==b[n-i+1].c){
			if(b[i].len>=b[n-i+1].len){
				pre+=b[i].len;
				nxt+=b[i].len;
				b[n-i].len-=abs(b[n-i+1].len-b[i].len);
				cnt1+=abs(b[n-i+1].len-b[i].len);
			}
			else{
				pre+=b[i].len;
				nxt+=b[i].len;
				b[n-i].len+=abs(b[n-i+1].len-b[i].len);
				cnt1+=abs(b[n-i+1].len-b[i].len);
			}
		}
	}
	pre=0,nxt=0;
	for(int i=l;i>=1;i--){
		if(pre>=l/2||nxt>=l/2)break;
		if(b[i].c!=b[n-i+1].c){
			if(b[i].len>=b[n-i+1].len){
				pre+=b[i].len;
				nxt+=b[i].len;
				b[n-i+2].len-=abs(b[n-i+1].len-b[i].len);
				cnt2+=b[i].len;
			}
			else{
				pre+=b[i].len;
				nxt+=b[i].len;
				b[n-i+2].len+=abs(b[n-i+1].len-b[i].len);
				cnt2+=b[n-i+1].len;
			}
		}
		if(b[i].c==b[n-i+1].c){
			if(b[i].len>=b[n-i+1].len){
				pre+=b[i].len;
				nxt+=b[i].len;
				b[n-i+2].len-=abs(b[n-i+1].len-b[i].len);
				cnt2+=abs(b[n-i+1].len-b[i].len);
			}
			else{
				pre+=b[i].len;
				nxt+=b[i].len;
				b[n-i+2].len+=abs(b[n-i+1].len-b[i].len);
				cnt2+=abs(b[n-i+1].len-b[i].len);
			}
		}
	}
	cout<<min(cnt1,cnt2);
}