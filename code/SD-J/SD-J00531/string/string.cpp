#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
string s;
int cnt;
bool b(string x){
	int len=x.size();
	bool flag=1;
	for(int i=0,j=len-1;i<=j;i++,j--){
		if(x[i]!=x[j]){
			flag=0;
			break;
		}
	}
	if(flag==1) return 1;
	else return 0;
}
void solve(){
	int len=s.size();
	for(int i=0,j=len-1;i<=j;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		int m;
		scanf("%lld",&m);
		char c;
		cin>>c; 
		for(int j=1;j<=m;j++){
			s+=c;
		}
	}
//	cout<<s<<endl;
	if(b(s)==1){
		printf("0");
		return 0;
	}
	solve();
	printf("%lld",cnt);
	return 0;
}

/*
3
2 a
2 b
1 c
*/

/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
