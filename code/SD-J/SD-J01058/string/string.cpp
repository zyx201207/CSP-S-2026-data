#include<bits/stdc++.h>
using namespace std;
long long a[100050],asum[100050];
char b[100050];
char s[100050]; 
long long cnt;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		cnt+=a[i];
		asum[i]=cnt;
	}
	int t=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[t]=b[i];
			t++;
		}
	}
	long long ans=0;
	for(int i=1;i<=cnt/2;i++){
		if(s[cnt+1-i]!=s[i])ans++;
	} 
	cout<<ans;
	return 0;
} 

