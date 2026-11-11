#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int sumA,sumB,sumC,sumD;
char r,x;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>b>>c>>d;
	r=b[b.size()-1],x=d[d.size()-1];
	for(int i=0;i<a.size();i++)sumA=sumA*10+a[i];
	for(int i=0;i<b.size()-1;i++)sumB=sumB*10+b[i];
	for(int i=0;i<c.size();i++)sumC=sumC*10+c[i];
	for(int i=0;i<d.size()-1;i++)sumD=sumD*10+d[i];
	if(sumA==sumC)ans+="1";
	else ans+="0";
	if(sumA==sumC&&sumB==sumD)ans+="1";
	else ans+="0";
	if(sumA==sumC&&sumB==sumD&&((r>='A'&&r<='C'&&x>='A'&&x<='C')||(r>='D'&&r<='F'&&x>='D'&&x<='F')))ans+="1";
	else ans+="0";
	if(sumA==sumC&&sumB==sumD&&((r>='A'&&r<='C'&&x>='A'&&x<='C'&&(r==x+1||x==r+1))||(r>='D'&&r<='F'&&x>='D'&&x<='F'&&(r==x+1||x==r+1))))ans+="1";
	else ans+="0";
	cout<<ans;
	return 0;
}
