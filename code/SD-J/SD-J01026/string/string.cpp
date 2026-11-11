#include<bits/stdc++.h>
using namespace std;
long long a[200010],ans,p,m;
string s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		m+=a[i];
	}
	m/=2+1;
	for(int i=1;i<=n;i++){
		m-=a[i];
		if(m<=0){
			m=i;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=n;j>=m;j--){
		
			if(a[i]>=a[j])ans=a[j];
			a[i]=a[i]-ans;
			a[j]=a[j]-ans;
			if(s[i]!=s[j])p+=ans;
			if((s[i]!=s[j-1]&&s[i+1]!=s[j-1])||s[i]==s[i+1]){
			a[i+1]+=a[i];
			continue;}
			if((s[j-1]!=s[i+1]&&s[j]!=s[i+1])||(s[j]==s[j-1])){
			a[j-1]+=a[j];
			continue;}
			if(s[i]==s[j-1]){
				a[j-1]-=a[i];
			}
			if(s[i+1]==s[j]){
				a[i+1]-=a[j];
			}
		}}
	
	cout<<p;
	return 0;
} 

