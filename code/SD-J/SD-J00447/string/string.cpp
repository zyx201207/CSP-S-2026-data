#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,s[N],ans,cnt,sum,s1;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
		sum+=s[i];
	}
	cnt=n;
	for(int i=1;i<=n/2+2;i++){
		while(s[i]>0){
			if(c[i]!=c[cnt]&&s[i]>s[cnt]){
				ans+=s[cnt];
				s[i]-=s[cnt];
				s[cnt]=0;
				cnt--;
			}
			else if(c[i]!=c[cnt]&&s[i]==s[cnt]){
				ans+=s[cnt];
				s[i]=0,s[cnt]=0;
				cnt--;
			}
			else if(c[i]!=c[cnt]&&s[i]<s[cnt]){
				ans+=s[i];
				s[cnt]-=s[i];
				s[i]=0;
			}
			else if(c[i]==c[cnt]&&s[i]==s[cnt]){
				s[i]=0,s[cnt]=0;
				cnt--;
			}
			else if(c[i]==c[cnt]&&s[i]<s[cnt]){
				s[cnt]-=s[i];
				s[i]=0;
			}
			else if(c[i]==c[cnt]&&s[i]>s[cnt]){
				s[i]-=s[cnt];
				s[cnt]=0;
				cnt--;
			}
		}
	}
	cout<<ans;
	return 0;
}
