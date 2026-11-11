#include<bits/stdc++.h>
using namespace std;
int n;
long long g=0;
struct hw{
	int a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	vector<hw> s(n);
	int q=0,h=n-1;
	for(int i=0;i<n;i++)
		cin>>s[i].a>>s[i].c;
	for(int i=0;i<n;i++){
		int m=min(s[q].a,s[h].a);
		if(s[q].c!=s[h].c)	g+=m;
		s[q].a-=m;
		s[h].a-=m;
		if(s[q].a==0)	q++;
		else if(s[h].a==0)	h--;
		if(q==h)	break;
	}
	cout<<g;
	return 0;
}