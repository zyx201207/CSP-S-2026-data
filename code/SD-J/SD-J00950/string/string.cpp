#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
long long a[MAXN];
char c[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,sum=0,ans=0;
	string s,st;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		sum+=a[i];
	} 
	st=s;
	reverse(s.begin(),s.end());
	long long len=s.size();
	for(int k=1;k<=len-1;k++){
		if(s[k]!=st[k]) cnt++;
	}
	int mid=sum/2;
	if(cnt>mid) ans=mid;
	else ans=cnt;
	printf("%d\n",ans);
	return 0;
}
