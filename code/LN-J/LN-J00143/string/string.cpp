#include<bits/stdc++.h>
using namespace std;
string T,S;
long long A[2000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,cnt=0;
    cin>>n;
    int i,j;
    for(i=1;i<=n;i++){
		cin>>A[i]>>T[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=A[i];j++){
			S=S+T[i];
		}
	}
	int len=S.size();
	for(i=0;i<len/2;i++){
		if(S[i]!=S[len-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}
