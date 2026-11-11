#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
struct node{
	int a;
	char c;
}S[N];
ll ans;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int m;
		char ch;
		cin>>m>>ch;
		S[i]={m,ch};
	}
	int l=1,r=n;
	while(l<r){
		int minn=min(S[l].a,S[r].a);
		S[l].a-=minn;
		S[r].a-=minn;
		if(S[l].c!=S[r].c) ans+=(ll)minn;
		if(S[l].a==0) l++;
		if(S[r].a==0) r--;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
