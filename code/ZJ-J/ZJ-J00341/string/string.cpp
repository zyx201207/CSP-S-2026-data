#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],k=0,m=0;
char b[N];
string s1,s2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
	  cin>>a[i]>>b[i];
	  m+=a[i];
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=a[i];j++)
	    s1+=b[i];
	for(int i=n;i>0;i--)
	  for(int j=1;j<=a[i];j++)
	    s2+=b[i];
	for(int i=0;i<m;i++)
	  if(s1[i]!=s2[i])k++;
	  cout<<k/2;
	return 0;
}
