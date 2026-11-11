#include<bits/stdc++.h>
using namespace std ;
	int n,t[200005],ans,cnt;
	char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>c[i];
		cnt+=t[i];
	}
	for(int i=1;i<=n;i++){
		if(c[i]==c[n+1-i]){
			if(t[i]!=t[n+1-i])ans+=max(t[i],t[n+i-1])-min(t[i],t[n+i-1]);
			else continue;
		}else{
			if(t[i]!=t[n+1-i])ans+=max(t[i],t[n+i-1]);
			else ans+=t[i];
		}
		if(i==n+1-i||i+1==n+1-i)break;
	}
	if(cnt%2!=0)cout<<ans-1;
	else cout<<ans;
	return 0;
}
