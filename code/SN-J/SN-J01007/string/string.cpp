//SN-J01007
//¶­¹ú¶°
#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a,b;
	char c;
}a[200005];
int n;
long long len,ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int l;
		char in;
		cin>>l>>in;
		a[i].a=len+1;
		a[i].b=a[i].a+l-1;
		a[i].c=in;
		len=a[i].b;
	}
	for(int l=1,r=n;l!=r;)
	{
		long long ll=a[l].a,lr=a[l].b;
		long long rr=len-a[r].a+1,rl=len-a[r].b+1;
		long long cl=max(ll,rl),cr=min(lr,rr);
//		cout<<ll<<' '<<lr<<'/'<<rl<<' '<<rr<<'/'<<cl<<' '<<cr<<endl;
		if(a[l].c!=a[r].c)
			ans+=(cr-cl+1);
		if(lr<rr)
			l++;
		else if(lr>rr)
			r--;
		else
		{
			if(abs(l-r)==1)
				break;
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
