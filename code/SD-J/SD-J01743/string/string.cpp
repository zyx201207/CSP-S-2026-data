#include<bits/stdc++.h>
using namespace std;//É¾µôfreopenµÄ×¢ÊÍ£¡£¡£¡ 
long long n,cnt,i;
string s;
void check_huiwen(string s)
{
	long long l=0,r=0;
	r=s.size()-1;
	while(l<=r)
	{
		if(s[l]!=s[r])
		{
			cnt++;
		}
		l++;
		r--;
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    while(n--)
    {
    	char a;
    	long long b;
    	cin>>b>>a;
    	while(b--)
        s+=a;
    	
	}
    check_huiwen(s);
    cout<<cnt;
	return 0;

}
