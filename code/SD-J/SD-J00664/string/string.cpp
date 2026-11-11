#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt;
string s,s2;
char a;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>m>>a;
		for(int i=1;i<=m;i++){
			s+=a;
		}
		
	}
	//cout<<s<<endl;
	s2=s;
	reverse(s.begin(),s.end());
	int le=s.size();
	if(le%2==1)le++;
	for(int i=0;i<le/2;i++){
		if(s[i]!=s2[i]){
			cnt++;
			
		}
	}
	cout<<cnt;
	return 0;
}

