#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
};
string s;
int cmp;
int n,sum,l,h;//sum答案,l下标,h余下的和
node m[20005],dp[20005];
node y;//y余下的数与字母
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>m[i].a>>m[i].c;
		for(int i=1;i<=m[i].a;i++){
			s=s+m[i].c;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]==s[s.size()-i-1]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
} 
