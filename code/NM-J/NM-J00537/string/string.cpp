#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long a[N],ljj,n;
string s[N];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
 cin>>a[i]>>s[i];	
long long L=1,R=n;
while(L<R)
{  
		long long h=0;
		if(a[L]<=a[R]) h=a[L];
		else h=a[R];
		if(s[L]!=s[R]) ljj+=h;
		a[L]-=h;
		a[R]-=h;
		if(a[L]<=0) L++;
		if(a[R]<=0) R--;
} 
cout<<ljj;
fclose(stdin);
fclose(stdout);
return 0;
}
