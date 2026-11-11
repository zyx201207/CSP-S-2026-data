#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);        
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long tot=0,cnt=1;
	for(int i=1;i<=n;i++){
		long long x;
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s[cnt]=c;
			cnt++;
		}
		tot+=x;
	}
	
	if(tot%2==0){
		long long mid=1ll*ceil(tot/2);
		mid++;
		string s1,s2;
		for(int i=1;i<=mid-1;i++){
			s1[i]=s[i];
		}
		for(int i=mid;i<=tot;i++){
			s2[i-mid+1]=s[i];
		}
		long long ans=0;
		for(int i=1;i<=mid-1;i++){
			if(s1[i]!=s2[i])
				ans++;
		}
		cout<<ans;
	}else{
		long long mid=1ll*ceil(1.0*tot/2);
		string s1,s2;
		for(int i=1;i<=mid-1;i++){
			s1[i]=s[i];
		}
		for(int i=mid+1;i<=tot;i++){
			s2[i-mid]=s[i];
		}
		long long ans=0;
		for(int i=1;i<=mid-1;i++){
			if(s1[i]!=s2[i])
				ans++;
		}
		cout<<ans;
	}
}
