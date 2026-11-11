#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long t,k,ans,sum_l;
struct _{
	long long l=0;
	char c;
}s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		ans++;
		cin>>s[ans].l>>s[ans].c;
		sum_l+=s[ans].l;
		if(t>1)s[ans].l+=s[ans-1].l;
	}
	long long sum_lm=(s[ans].l+1)/2;
	for(long long i=sum_lm+1;i<=s[ans].l;i++){
		long long n=sum_l+1-i;
		long long l=1,r=t,vis1,vis2;
		while(l<=r){
			long long mid=(l+r)/2;
			if(n<=s[mid].l&&n>s[mid-1].l){
				vis1=mid;
				break;
			}
			if(n>s[mid].l)l=mid+1;
			else r=mid-1;
		}
		l=1,r=t;
		while(l<=r){
			long long mid=(l+r)/2;
			if(i<=s[mid].l&&i>s[mid-1].l){
				vis2=mid;
				break;
			}
			if(i>s[mid].l)l=mid+1;
			else r=mid-1;
		}
		if(s[vis1].c!=s[vis2].c)k++;
	} 
	cout<<k;
}

