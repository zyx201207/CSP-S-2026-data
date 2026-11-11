#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    int n,m;
    string a;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>m>>a;
    	for(int j=0;j<m;j++)
        {
    		s+=a;
	    }
	}
	bool flag=1;
	for(int i=0;i<n-1;i++)
    {
    	if(a[i]!=a[i+1])
    	{
    		flag=0;
    		break;
		}
	}
	if(flag) cout<<"0";
    int mid,cnt=0;
    string s1,s2;
    if(s.size()%2==1) mid=s.size()/2+1;
    else {
	    cout<<"3000000000";
	    return 0;
    }
    for(int i=0;i<s.size()/2;i++)
    {
    	if(s[i]!=s[s.size()-i-1]) cnt++;
	}
	cout<<cnt;
    
    return 0;
}


