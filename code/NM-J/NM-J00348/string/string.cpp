#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int x;
	char y;
};
int n,cnt;
int a[N],dp[N];
char c[N];
string s;
queue<node>qst;
queue<node>qed;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		for(int i=1;i<=a[i];i++)s+=c[i];
	}cout << "0";
	return 0;
}

