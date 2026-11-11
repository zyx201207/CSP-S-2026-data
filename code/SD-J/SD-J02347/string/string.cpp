#include<bits/stdc++.h>
using namespace std;
long long s[1000010];
long long cnt=1;
long long a[10001];
char c[10001];
int n;
long long ans[5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		c[i]=c[i]-'0';
		for(int j=1;j<=a[i];j++){
			s[cnt++]=c[i];
		}	
	}
	for(int i=1;i<=cnt/2;i++){
			if(s[i]!=s[i+cnt/2]){
				s[i+cnt/2]=s[i];
				ans[1]++;
			}
		}
	for(int i=1;i<=cnt/2;i++){
			if(s[i]!=s[i+cnt/2]){
				s[i]=s[i+cnt/2];
				ans[2]++;
			}
		}
		sort(ans,ans+2);
		cout<<ans[1]-1;
	return 0;
} 
