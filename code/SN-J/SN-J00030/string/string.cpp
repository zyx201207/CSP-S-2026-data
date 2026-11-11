#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2 * 100000 + 1;
int n,ans;
string r,r1;
string L,L1;//记录字符串 
bool vis[N];
struct node{
	int a;
	char c;
}zh[N]; //记录每段 

int check(){
	char s = zh[1].c;
	for(int i=1;i<=n;i++){
		 if(L[i] != s) ans++;
	}
	return ans;
}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> zh[i].a >> zh[i].c;
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=zh[i].a;j++) L += zh[i].c;
	}
	L1 = L;
	reverse(L1.begin(),L1.end());
	if(L1 == L){//本身就是回文串  
		cout << 0;
		return 0;
	}
	else cout <<check();//不然就枚举	
	 
	return 0;
}

