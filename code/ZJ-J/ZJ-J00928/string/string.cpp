#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}A[200010];
string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i].a>>A[i].c;
	}
	long long int cnt=0,N=0;
	for(int i=1;i<=n;i++){
		N+=A[i].a;
		for(int j=1;j<=A[i].a;j++){
			S=S+A[i].c;
		}
	}
	bool flag=1;
	for(int i=0;i<N;i++){
		if(S[i]!=S[N-i-1]){
			flag=0;
			cnt++;
		}
	}
	if(flag) cout<<0;
	else cout<<cnt/2;
	return 0;
}