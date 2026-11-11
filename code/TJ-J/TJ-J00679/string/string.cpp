#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
unsigned long long ln;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>ln>>a;
		for(int i=1;i<=ln;i++)s+=a;
	}
	unsigned long long sum=0;
	unsigned long long ans=0;
	if(s.size()/2==0)
	{
		ans=s.size()/2;
	}
	else
	{
		ans=s.size()/2+1;
	}
	for(int i=0;i<ans;i++)
	{
		if(s[i]!=s[s.size()-i-1])sum++;
	}
	cout<<sum;
	return 0;
}
