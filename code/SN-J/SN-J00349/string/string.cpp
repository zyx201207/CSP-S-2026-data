#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	unsigned long long n,ans=0,a[200005],ci;
	char c[200005];
	string str;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
			str+=c[i];
	}
	if(str.size()%2==0)
		ci=str.size()/2;
	else
		ci=str.size()/2+1;
	for(int i=0;i<ci;i++)
		if(str[i]!=str[str.size()-1-i])
			ans++;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
