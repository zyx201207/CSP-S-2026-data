#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
char a[N];
bool cmp(int A,int B)
{
	return A>B;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	string s=a[1]&a[2];
	cout<<s;
 } 
