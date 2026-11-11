#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,t,sum,cnt,ans;
int a[200010];
string p,q;
char c[200010];
bool check(int a,int b){
	while(a>0){
		p+=a%2;
		a/=2;
		l++;
	}
	while(b>0){
		q+=b%2;
		b/=2;
		r++;
	}
	t=max(l,r);
	for(int i=1;i<=t;i++){
		if(q[i]==p[i]){
			c[i]=0;
		} else {
			c[i]=1;
		}
	}
	cnt=1;
	for(int i=t;i>=1;i--){
		if(c[i]%10==1){
			sum+=cnt;
			cnt*=2;
		}
		c[i]/=10;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			check(a[i],a[j]);
			ans=max(ans,sum);
		}
	}
	cout<<ans;
	return 0;
}