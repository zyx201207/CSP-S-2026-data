#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
inline int read(){
	char c=getchar();LL ans=0,p=1;
	while (c<'0'||c>'9'){if (c=='-') p=-1;c=getchar();}
	while (c>='0'&&c<='9'){ans=ans*10+(c-48);c=getchar();}
	return ans*p;
}
LL a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	LL n=read(),m=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	LL ans=1;
	LL sum=0;
	LL i=1,j=1;
	while (i<n){
		while (sum+(i-j+1)*(a[i+1]-a[i])>m){
			sum-=a[i]-a[j];
			j++;
		}
		sum+=(i-j+1)*(a[i+1]-a[i]);
		ans=max(ans,i-j+1);
//		cout<<sum<<" "; 
		i++;
	}
	cout<<ans+1;
	return 0;
}
