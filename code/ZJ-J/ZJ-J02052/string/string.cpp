#include<bits/stdc++.h>
#define IO freopen("string.in","r",stdin);freopen("string.out","w",stdout);
using namespace std;
const int MAXN=2e5+10;
long long int A[MAXN];
char S[MAXN];
int main(){
	IO
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i]>>S[i];
	}
	long long int ans=0;
	int l=1,r=n;
	long long int nowl=0,nowr=0;
	while(l<r){
		if(S[l]==S[r]){
			if(A[l]-nowl>A[r]-nowr){
				nowl+=A[r]-nowr;
				nowr=0;
				r--;
			}
			else if(A[l]-nowl<A[r]-nowr){
				nowr+=A[l]-nowl;
				nowl=0;
				l++;
			}
			else{
				nowr=nowl=0;
				l++;r--;
			}
		}
		else{
			if(A[l]-nowl>A[r]-nowr){
				ans+=A[r]-nowr;
				nowl+=A[r]-nowr;
				nowr=0;
				r--;
			}
			else if(A[l]-nowl<A[r]-nowr){
				ans+=A[l]-nowl;
				nowr+=A[l]-nowl;
				nowl=0;
				l++;
			}
			else{
				ans+=A[r]-nowr;
				nowr=nowl=0;
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
