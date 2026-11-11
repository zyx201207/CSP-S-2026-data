#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200003
ll a[maxn],b,c,d,i,j,k,m,n,ans,sum,tot,cnt,l,r,p,x,y,t,dis[maxn];
string s1,s2,s3,s4;
char s[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		tot+=a[i];
	}
	
	cnt=a[1],sum=a[n];
	if(tot%2==0){
		for(i=1,j=n;;){
			if(a[i-1]==0&&a[j-1]==0&&i-j==1)break;
			if(i-j==1)break;
			if(a[i]>a[j]){
				if(s[i]!=s[j])ans+=a[j];
				a[i]-=a[j],sum+=a[--j];
			}
			else if(a[i]==a[j]){
				if(s[i]!=s[j])ans+=a[i]; 	
				a[i++]=a[j--]=0;	
			}
			else{
				if(s[i]!=s[j])ans+=a[j]-a[i];
				a[j]-=a[i],cnt+=a[--i];
			}
		}
	}
	else{
		for(i=1,j=n;;){
			if(a[i]==0&&a[j]==0&&i==j)break;
			if(i==j)break;
			if(a[i]>a[j]){
				if(s[i]!=s[j])ans+=a[j];
				a[i]-=a[j],sum+=a[--j];
			}
			else if(a[i]==a[j]){
				if(s[i]!=s[j])ans+=a[i]; 
				i++,j--;
			}
			else{
				if(s[i]!=s[j])ans+=a[i];
				a[j]-=a[i],cnt+=a[++i];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
