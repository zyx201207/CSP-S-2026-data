#include<bits/stdc++.h>
#define ll long long
#define int long long
#define N 1
#define M 1
#define rep(a,b,c) for(int a=(b);a<=(c);a++)
using namespace std;
char c[10]={'A','B','C','D','F'};
string s[10];
bool pan=1;
ll a[10];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	if(s[1]!=s[3])pan=0;
	cout<<pan;
	if(s[2][1]!=s[4][1]||s[2][0]!=s[4][0])pan=0;
	cout<<pan;
	for(int i=0;i<5;i++){
		if(s[2][2]==c[i])a[1]=i;
		if(s[4][2]==c[i])a[2]=i;
	}
	if((a[1]<3&&a[2]>=3)||((a[2]<3&&a[1]>=3)))pan=0;
	cout<<pan;
	if(abs(a[1]-a[2])>1)pan=0;
	cout<<pan;
	return 0;
} 
//Trick||Treat!
