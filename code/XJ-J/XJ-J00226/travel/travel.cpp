#include<bits/stdc++.h>
using namespace std;
long long int c1,c2;
char s1[100000000],s2[10000000000];
char sum[1000000];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
		cin>>c1;
	for(int i=1;i<=3;i++)
		cin>>s1[i];
		cin>>c2;
	for(int i=1;i<=3;i++)
		cin>>s2[i];
	if(c1!=c2){
	sum[1]='0';
	sum[2]='0';
	sum[3]='0';
	sum[4]='0';
	}
	else{
		sum[1]='1';
	if(s1[1]!=s2[1]||s1[2]!=s2[2])
	{
		sum[2]='0';
		sum[3]='0';
		sum[4]='0';
	}
	else{
		sum[2]='1';
	if(s1[3]=='A'||'B'||'C')
	if(s2[3]=='D'||'F')
	sum[3]='0';
	else
	if(s2[3]=='A'||'B'||'C')
	sum[3]='1';
	if(s1[3]=='A'&&s2[3]=='B'||s1[3]=='B'&&s2[3]=='C'||s1[3]=='D'&&s2[3]=='F')
	sum[4]='1';
	else sum[4]='0';
	}
	}
	for(int i=1;i<=4;i++)
	cout<<sum[i];
	return 0;
}
