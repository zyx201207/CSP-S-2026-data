#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char s[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int l=1,r,n;
	long long x=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>s[i];
	r=n;
	while(1)
	{
		if(s[l]!=s[r])x++;
		a[l]--;
		a[r]--;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		if(l+1==r)
		{
			if(a[l]!=a[r])
			{
				if(s[l]!=s[r])x=x+min(a[l],a[r]);
				break;
			}
			else{
				if(s[l]!=s[r])x=x+a[l];
				break;
			}
		}
	}
	cout<<x;
	return 0;
}
