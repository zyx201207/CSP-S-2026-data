#include<bits/stdc++.h>
using namespace std;
struct str{int a;char c;};
str s[2000010];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i,s1=0,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>s[i].a>>s[i].c;
	}
	for(i=1,j=n;;)
	{
		
		if((int)s[i].c!=(int)s[j].c)
		{
			if(s[i].a==s[j].a) s1+=s[j].a,i++,j--;
			else if(s[i].a>s[j].a) s1+=s[j].a,s[i].a=abs(s[i].a-s[j].a),j--;
			else if(s[i].a<s[j].a) s1+=s[i].a,s[j].a=abs(s[i].a-s[j].a),i++;
		}
		else 
		{
			if(s[i].a==s[j].a) i++,j--;
			else if(s[i].a>s[j].a) s[i].a=abs(s[i].a-s[j].a),j--;
			else if(s[i].a<s[j].a) s[j].a=abs(s[i].a-s[j].a),i++;
		}if(i>=j) break;
	}
	cout<<s1;
	return 0;
}
