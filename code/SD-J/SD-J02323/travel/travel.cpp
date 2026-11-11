#include<bits/stdc++.h>
#define int long long
using namespace std;
char c1,c2;
int a[10],s1,s2,s3,s4,k,t;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>c1>>s3>>s4>>c2;
	k=c1;
	t=c2;
	if(s1==s3 && (s1!=1||s1!=16)){
		a[1]=1;
		if(s2==s4){
			a[2]=1;
			if(((k>=64 && k<=67)&&(t>=64 && t<=67))||((k==67&&t==69)||(t==67&&k==69)))
				a[3]=1;	
			if((c1=='C' && c2=='D')||(c2=='C'&&c1=='D'))
				a[4]=0;
			else if((k-t==1||t-k==1)||((c1=='D'&&c2=='F')||(c1=='F'&&c2=='D')))
				a[4]=1;
		}
	}
	for(int i=1;i<=4;i++)
		cout<<a[i];
	return 0;
} 
