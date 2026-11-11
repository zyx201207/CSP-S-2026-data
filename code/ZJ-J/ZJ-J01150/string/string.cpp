#include<bits/stdc++.h>
using namespace std;
int s[200005];
char v[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i]>>v[i];
	int i=1,j=n;
	long long ans=0;
	while(i<j){
		if(v[i]==v[j]){
			if(s[i]==s[j])i++,j--;
			else if(s[i]<s[j])s[j]-=s[i],i++;
			else s[i]-=s[j],j--;
		}else{
			ans+=min(s[i],s[j]);
			if(s[i]==s[j])i++,j--;
			else if(s[i]<s[j])s[j]-=s[i],i++;
			else s[i]-=s[j],j--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}