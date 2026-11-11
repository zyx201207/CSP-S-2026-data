#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,i,l,r,sl,sr,ans,a[200010];
char cl,cr,c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	l=1;r=n;sl=a[1];sr=a[n];cl=c[1];cr=c[n];
	while(l<=r)
	{
		if(sl==sr)
		{
			if(cl!=cr)ans+=sl;
			sl=a[++l],sr=a[--r];
			cl=c[l];cr=c[r];
		}
		else if(sl<sr)
		{
			if(cl!=cr)ans+=sl;
			sr-=sl;sl=a[++l];
			cl=c[l];
		}
		else
		{
			if(cl!=cr)ans+=sr;
			sl-=sr;sr=a[--r];
			cr=c[r];
		}
		//cout<<sl<<" "<<sr<<"\n";
	}
	cout<<ans;
}
