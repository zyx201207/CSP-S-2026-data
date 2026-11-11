#include<bits/stdc++.h>
using namespace std;
long long s[500099];
int main(){
	
//	ios::sync_with_stdio(0);cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m,sum=0,ans=0,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		sum+=s[i];
	}
	sum=sum/n;
	sort(s+1,s+1+n); 
	long long z=lower_bound(s+1,s+1+n,sum)-s;
	long long cs=s[z];
	for(int i=z+1;i<=n;i++){
		if(s[i]>s[z]){
			z=i-1;
			break;
		}
	}
	for(int i=z;i>=1;i--){
		if((ans+s[z]-s[i])>m){
			cout<<cnt;
			return 0;
		}
		ans=ans+s[z]-s[i];
		cnt++;
	}
	for(int i=z+1;i<=n;i++){
		if(ans+z*(s[i]-s[z])<=m){
			ans=ans+z*(s[i]-s[z]);
			cnt++; 
		}
		else {
			cout<<cnt;
			return 0;
		}
	}
	cout<<cnt;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
