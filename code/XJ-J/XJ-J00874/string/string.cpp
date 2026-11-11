#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b;
	long long n,s[200010]={},sum=0,cnt=0;
	char c[200010]={};
	cin>>n;
	if(n==1){
		cin>>s[1]>>c[1];
		cout<<0;
		return 0;
	}
	if(n==2){
		cin>>s[1]>>c[1];
		cin>>s[2]>>c[2];
		if(c[1]==c[2]){
			cout<<0;
			return 0;
		}
		else{
			int mi=min(s[1],s[2]);
			cout<<mi;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>s[i]>>c[i];
		sum+=s[i];
		for(int j=1;j<=s[i];j++)
		a[j]=c[i];
	}
	int j=1;
	for(int i=sum/2+1;i<=sum;i++){
		b[j]=a[i];
		j++;
	}
	for(int i=1;i<=sum/2;i++)
	{
		if(a[i]!=b[i])
		{
			cnt++;	
		}
	}
	cout<<cnt;
	return 0;
	
 } 