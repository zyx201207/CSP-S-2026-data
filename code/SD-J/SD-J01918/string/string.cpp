#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NMAX=2e5+33333;
struct node{
	int a;
	char c;
}s[NMAX];
int cnt=0;
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int aa;
		char cc;
		cin>>aa>>cc;
		s[i].a=aa;
		s[i].c=cc;
	}
	int l=1,r=n;
	while(l<=r){
		int op=min(s[l].a,s[r].a);
		if(s[l].c!=s[r].c){
			cnt+=op;
		}
		if(l!=r){
			s[l].a-=op;
			s[r].a-=op;	
		}
		else s[l].a-=op;
		if(s[l].a==0){
			l++;
		}
		if(s[r].a==0){
			r--;
		}
	}
	cout<<cnt;
	return 0;
}
