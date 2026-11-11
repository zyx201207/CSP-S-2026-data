#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],lb,rb;
long long ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
	}
	lb=1,rb=n;
	while(lb<rb){
//		cout<<1;
		if(c[lb]!=c[rb]){
			ans+=min(a[lb],a[rb]);
		}
		if(a[lb]<a[rb]){
//			l+=a[lb];
			a[rb]-=a[lb];
			lb++;
		}else if(a[lb]>a[rb]){
//			r-=a[rb];
			a[lb]-=a[rb];
			rb--;
		}else{
			lb++;
			rb--;
		}
	}
	cout<<ans;
	return 0;
}
//for /L %i in (1,1,5) do @(string<string%i.in>string%i.out&&fc string%i.out string%i.ans)
//100pts