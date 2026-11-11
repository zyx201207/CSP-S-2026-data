#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	long long w=0;
	for(int i=1;i<=n;i++)
	{
		long long a;
		char c;
		cin>>a>>c;
		s[w]=c;
		w+=a;
	}
	string l,r;
	long long len=0;
	bool ok=0;
	if(w%2==0)
		len==w/2;
	else{
		ok=1;
		len=w/2+1;
	} 
	char ch=s[0];
	long long rlen=0;
	for(int i=0;i<w;i++)
	{
		if(s[i]>='a'&&s[i]<='z')
			ch=s[i];
		s[i]=ch;
		if(i<len)l[i]=s[i];
		else{
			if(ok){
				r[0]=s[i-1];
				rlen=1;
				ok=0;
			}
			r[rlen]=s[i];
			rlen++;
		}
	}
	long long ans=0;
	for(int li=0,ri=len-1;li<len && ri>=0;li++,ri--)
		if(l[li]!=r[ri])ans++;
	cout<<ans;
	return 0;
}
