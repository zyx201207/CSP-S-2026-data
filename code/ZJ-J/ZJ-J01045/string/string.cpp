#include <iostream>
#include <string>
using namespace std;
const int N=2e5+100;
struct node{
	int a,l,r;
	char c;
}s[N];
long long len;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> s[i].a >> s[i].c;
		s[i].l=s[i-1].r+1,s[i].r=s[i].l+s[i].a;
		len+=s[i].a;
	}long long mid=len/2,pos=0;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=s[i].a;
		if(cnt>=mid)pos=i;
	}long long ans=0;
	long long now=0,l=1,r=n;
	while(l!=pos and r!=pos){
		if(s[l].c!=s[r].c){
			long long le=s[l].r-now+s[l].l;
			long long re=s[r].l-(len-now)+s[r].r;
			if(le>re){
				ans+=re;
				now+=re;
				r--;
			}else{
				ans+=le;
				now+=le;
				l++;
			}
		}else{
			long long le=s[l].r-now+s[l].l;
			long long re=s[r].l-(len-now)+s[r].r;
			if(le>re){
				now+=re;
				r--;
			}else{
				now+=le;
				l++;
			}
		}
	}if(s[l].c!=s[pos].c or s[r].c!=s[pos].c){
		ans+=mid-now;
	}
	cout << ans;
	return 0;
}
