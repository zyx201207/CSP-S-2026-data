#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
long long n,a[200010],ans;
char s[200010];
int main(){
	fast;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	long long l=1,r=n,sum1=a[1],sum2=a[n],c1=s[1],c2=s[n];
	while(l<=r){
		long long x=min(sum1,sum2);
		if(c1!=c2){
			ans+=x;
		}
		sum1-=x;
		sum2-=x;
		if(sum1==0){
			l++;
			sum1+=a[l];
			c1=s[l];
		}
		if(sum2==0){
			r--;
			sum2+=a[r];
			c2=s[r];
		}
		if(l==r){
			break;
		}
	}
	cout<<ans;
	return 0;
}
