#include<bits/stdc++.h>
using namespace std;
long long n,t,p=1,si,u,ans;
map<long long,string> s;
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t>>a;
		si+=t;
		while(t--){
			s[p]=a;
			p++;
		}
	}
	for(long long i=1;i<=si/2;i++)
	{
		if(s[i]!=s[p-i])
		{
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
