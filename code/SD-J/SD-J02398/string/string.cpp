#include<bits/stdc++.h>
using namespace std;
int n,a,sum,ans;char c;string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++){
			s[++cnt]=c;
		}
	}
	if(sum%2==0){
		if(sum==2){
			cout<<1;
			return 0;
		}
		int i=1;
		if(s[sum/2]!=s[sum/2+1])ans++;
		while(i!=sum/2){
			if(s[i]!=s[sum-i+1]){
				ans++;
			}
			i++;
		}
		cout<<ans;
		return 0;
	}
	if(sum%2!=0){
		if(sum==1){
			cout<<0;
			return 0;
		}
		int i=1;
		while(i!=sum/2+1){
			if(s[i]!=s[sum-i+1]){
				ans++;
			}
			i++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
