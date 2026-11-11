#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200050];
char s[200050];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		len+=a[i];
	}
	long long ans=0;
	long long cnt1=a[1],cnt2=a[n];
	long long cur1=1,cur2=n;
	while(len!=0){
		int x=min(cnt1,cnt2);
		len-=x;
		if(s[cur1]!=s[cur2])ans+=x;
		cnt1-=x;
		cnt2-=x;
		if(cnt1==0){
			cur1++;
			cnt1=a[cur1];
		}
		if(cnt2==0){
			cur2--;
			cnt2=a[cur2];
		}
	}
	cout<<ans/2;
	return 0;
}
