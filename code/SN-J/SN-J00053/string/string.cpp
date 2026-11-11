#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,a[N],b[N],ans=0,cnt=0,sum=0;
char c[N];
void check(int x){
	while(a[x]>b[cnt+1]-b[cnt]-sum){
		if(c[cnt+1]!=c[x])
		    ans+=b[cnt+1]-b[cnt]-sum;
		a[x]-=(b[cnt+1]-b[cnt]-sum);
		cnt++;
	}
	if(a[x]!=0){
		sum=a[x];
		if(c[cnt+1]!=c[x])
		    ans+=sum;
		cnt++;
		if(sum==b[cnt]-b[cnt-1]) sum=0;
	}else sum=0;
}
void check1(int x){
	if(sum==0) return ;
	if(sum!=0&&cnt>=x) return ;
	ans+=b[cnt]-(sum+b[cnt-1]);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i];
    }
    for(int i=n;i>=n/2+2;i--)
    	check(i);
    if(n%2==0) check(n/2+1);
    else check1(n/2+1);
    cout<<ans;
	return 0;
}
