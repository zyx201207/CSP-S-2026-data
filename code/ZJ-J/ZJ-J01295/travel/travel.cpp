#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)	cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}	
	int sum=0,sum1=0;
	int l=b.size();
	for(int i=0;i<l;i++){
		if(b[i]>='0'&&b[i]<='9'){
			sum+=sum*10+b[i]-'0';
			sum1+=sum1*10+d[i]-'0';
		}
		else{
			n=b[i];
			m=d[i];
		}
	}
	if(sum==sum1)	cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((n>='A'&&n<='C')&&(m>='A'&&m<='C')||(n>='D'&&n<='F')&&(m>='D'&&m<='F'))	cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(n=='D'&&m=='F'||n=='F'&&m=='D')	cout<<1;
	else if(n!='D'&&m!='D'&&n!='F'&&m!='F'){
		if(n==m+1||m==n+1)	cout<<1;
		else cout<<0;
	}
	else	cout<<0;
	return 0;
}
