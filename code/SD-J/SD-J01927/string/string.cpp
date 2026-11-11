#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
unsigned long long ns;
long long a[N];
char c[N];
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	for(int i=0;i<n;i++) for(int j=0;j<a[i];j++) s+=c[i];
	for(unsigned long long i=0,j=s.size()-1;i<=j;i++,j--) if(s[i]!=s[j]) ns++;
	cout<<ns;
	return 0;
}
