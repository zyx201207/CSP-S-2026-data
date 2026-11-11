#include<bits/stdc++.h>
#define int long long
using namespace std;
//#define fr(x) freopen(#x".in","r",stdin)
//#define fw(x) freopen(#x".out","w",stdout)
int n;
const int N=200005;
int val[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>val[i]>>c[i];
	}
	int i=1,j=n,ans=0;
	while(i<j){
		if(val[i]<val[j]){
			if(c[i]!=c[j])ans+=val[i];
			val[j]-=val[i];
			i++;
		}else if(val[i]==val[j]){
			if(c[i]!=c[j])ans+=val[i];
			i++,j--;
		}else{
			if(c[i]!=c[j])ans+=val[j];
			val[i]-=val[j];
			j--;
		}
//		cerr<<i<<' '<<j<<' '<<ans<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}
/*
hui wen chuan gai na bian dou yi yang
suo yi yu dao bu dui de di fang zhi jie +1 jiu ke yi le

*/
