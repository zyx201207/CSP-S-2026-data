#include<bits/stdc++.h>
using namespace std;

#define int long long
using P = pair<int,int>;

const int N=2e5+5;

string c[10],s[10];
string a[10],b[10];
bool ans[10];
void solve(){
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	
	a[1]=s[1][0]+s[1][1];
	a[2]=s[2][0]+s[2][1];
	b[1]=s[1][2];
	b[2]=s[2][2];
	
	ans[1]=(c[1]==c[2]);
	ans[2]=(a[1]==a[2]);
	
	ans[3]=0;
	ans[3]|=((b[1]=="A"&&b[2]=="B")||(b[2]=="A"&&b[1]=="B"));
	ans[3]|=((b[1]=="A"&&b[2]=="C")||(b[2]=="A"&&b[1]=="C"));
	ans[3]|=((b[1]=="C"&&b[2]=="B")||(b[2]=="C"&&b[1]=="B"));
	
	ans[3]|=((b[1]=="D"&&b[2]=="E")||(b[2]=="D"&&b[1]=="E"));
	
	ans[4]=0;
	ans[4]|=((b[1]=="A"&&b[2]=="B")||(b[2]=="A"&&b[1]=="B"));
	ans[4]|=((b[1]=="B"&&b[2]=="C")||(b[2]=="B"&&b[1]=="C"));
	ans[4]|=((b[1]=="D"&&b[2]=="E")||(b[2]=="D"&&b[1]=="E"));

	ans[0]=1;
	for(int i=1;i<=4;i++){
		ans[i]&=ans[i-1];
		cout<<ans[i];
	}
	cout<<endl;
}

int t_;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
	t_=1;
//	cin>>t_;
	while(t_--){
		solve();
	}
	
//	cout.flush();
	
	return 0;
}
