#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#define endl '\n'
using namespace std;
const int N=2e5+7;
struct Node{
	int a;
	char b;
}t[N];
char s[1000009];
int cnt,idx,len;
int main(){
	
	ios::sync_with_stdio(nullptr);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i].a>>t[i].b;
		len+=t[i].a;
		for(int j=0;j<t[i].a;j++){
			s[idx++]=t[i].b;
		}
	}
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])cnt++;
	}
	cout<<cnt;
	
	return 0;
}//01234 5 0 4 1 3
