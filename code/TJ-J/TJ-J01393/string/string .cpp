#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main()
{
	freopen("string .in","r",stdin);
	freopen("string .out","w",stdout);
	string s,c;
	int l,cnt=0;
	cin>>l;
	for(int i=0;i<l;i++){
		cin>>a[i]>>c;
		for(int i=1;i<=a[i];i++){
			long long len=s.size();
			s[s.size()+1]=c;
		}
	}
	if(nervers(s.begin(),s.end())==s){
		cout<<0;
	}
	return 0;
}
