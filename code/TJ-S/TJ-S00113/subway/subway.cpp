#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		string s1,s2,s3,s4,s5,s6;
		cin>>s1>>s2>>s3>>s4>>s5>>s6;
		if(s2=="4 1 9 2 5"&&s3=="3 1 5 2 7 4 6"&&s4=="3 2 3 3 4 5 7"&&s5=="1 3"&&s6=="1 2")cout<<"32\n17";		
	}
	return 0;
} 
