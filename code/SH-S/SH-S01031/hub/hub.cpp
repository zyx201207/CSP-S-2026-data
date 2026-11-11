#include <bits/stdc++.h>
using namespace std;
int c,t,n,k;
string s;
int st[100005],ed[100005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int sk=1;sk<=t;++sk){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			cin>>st[i]>>ed[i];
		}
		long long siz=s.size();
		long long l=0,r=siz-1,ans=0;
		if (siz%2==0)
		{
			while (l<=siz/2 && r>=siz/2)
			{
				if (s[l]!=s[r]) ans++;
				l++;r--;
			}
		}
		else
		{
			while (l<=siz/2-1 && r>=siz/2+1)
			{
				if (s[l]!=s[r]) ans++;
				l++;r--;
			}
		}
		
		cout << ans;
		cout<<"1"<<endl;
	} 
	return 0;
}
