#include<bits/stdc++.h>
using namespace std;
struct str{
	long long o;
	char w;
};
str s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		sum+=a;
		s[i].o=sum;
		s[i].w=c;
	}
	int l=1,r=n;
	for(long long i=1;i<=sum/(long long)2;i++){
		if(i>s[l].o){
			l++;
		}
		if(sum-i+1<=s[r-1].o){
			r--;
		}
		if(s[l].w!=s[r].w){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
