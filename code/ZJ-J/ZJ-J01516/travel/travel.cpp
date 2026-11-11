#include<bits/stdc++.h>
using namespace std;
string s0,s1,s2,s3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s0>>s1>>s2>>s3;
	if(s0==s2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s3[0]&&s1[1]==s3[1]) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	string A="A",B="B",C="C",D="D",F="F";
	if((s1[2]==A[0]&&s3[2]==B[0])||(s1[2]==B[0]&&s3[2]==A[0])||
	(s1[2]==A[0]&&s3[2]==C[0])||(s1[2]==C[0]&&s3[2]==A[0])||
	(s1[2]==B[0]&&s3[2]==C[0])||(s1[2]==C[0]&&s3[2]==B[0])||
	(s1[2]==D[0]&&s3[2]==F[0])||(s1[2]==F[0]&&s3[2]==D[0]))
	cout<<"1";
	else cout<<"0";
	if((s1[2]==A[0]&&s3[2]==B[0])||(s1[2]==B[0]&&s3[2]==A[0])||
	(s1[2]==B[0]&&s3[2]==C[0])||(s1[2]==C[0]&&s3[2]==B[0])||
	(s1[2]==D[0]&&s3[2]==F[0])||(s1[2]==F[0]&&s3[2]==D[0]))
	cout<<"1";
	else cout<<"0";
}
