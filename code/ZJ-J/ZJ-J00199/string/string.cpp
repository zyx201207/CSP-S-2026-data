#include<bits/stdc++.h>
using namespace std;
long long n,i,S,s,t,w,now1,now2,s1,s2,ans,a[200010],sum[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>c[i],s+=a[i],sum[i]=sum[i-1]+a[i];
	for(i=1;i<=n;i++){
		S+=a[i];
		if(s%2&&S>s/2)break;
		if(s%2==0&&S>=s/2)break;
	}
	if(s%2)t=i,w=i,now1=s/2+1,now2=s/2+1;
	if(s%2==0){
		now1=s/2;
		now2=s/2+1;
		if(S==s/2)t=i,w=i+1;
		else t=i,w=i;
	}
	while(t>=1||w<=n){
		s1=sum[t-1]+1;
		s2=sum[w];
		if(now1-s1+1<s2-now2+1){
			if(c[t]!=c[w])ans=ans+now1-s1+1;
			now2=now2+now1-s1+1;now1=s1-1;t--;
		}
		else if(now1-s1+1==s2-now2+1){
			if(c[t]!=c[w])ans=ans+now1-s1+1;
			now1=s1-1;now2=s2+1;t--;w++;
		}
		else{
			if(c[t]!=c[w])ans=ans+s2-now2+1;
			now1=now1-(s2-now2+1);now2=s2+1;w++;
		}
	}
	cout<<ans;
	return 0;
}