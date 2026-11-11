#include<bits/stdc++.h>
using namespace std;
int n;
long long t,ans;
string s,sc;
long long a[200010];
char c[200010]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		scanf(" %s",&c[i]);
		t+=a[i];
	}	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<(t/2);i++)	sc+=s[i];
	for(int i=t-1;i>=((t+1)/2);i--){
		if(s[i]!=sc[t-i-1])	ans++;
	}
	printf("%lld",ans);
	return 0;
}
