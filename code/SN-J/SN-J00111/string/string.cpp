#include<bits/stdc++.h>
using namespace std;
int n;
string s;
struct node{
	int x;
	char ch;
}a[200005];
bool ck(string x)
{
	string c="";
	for(int i=x.size()-1; i>=0; i--) c+=x[i]; 
	if(x==s) return true;
	else return false;
}
int tutu(string x)
{
	int cnt=0;
	int l=0, r=x.size()-1;
	for(int i=l; i<=r; i++)
	{
		if(x[l]!=x[r])
	    {
	    	cnt++;
		    x[r]=x[l];
		    if(ck(x)) break;
		    r--;
		    l++;
	    }
	}
	return cnt;
}
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i].x >> a[i].ch;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=a[i].x; j++)
		{
			s+=a[i].ch;
		}
	}
	if(ck(s)) cout << 0;
	else cout << tutu(s);
	return 0;
}
