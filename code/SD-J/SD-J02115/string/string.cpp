#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long cnt;
struct node{
	int a;
	char s1;
}ss[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>ss[i].a>>ss[i].s1;
	for(int i=1,j=n;i<=j;){
		int minn=min(ss[i].a,ss[j].a);
		if(ss[i].s1!=ss[j].s1) cnt+=minn;
		ss[i].a-=minn;
		ss[j].a-=minn;
		if(ss[i].a<=0) i++;
		if(ss[j].a<=0) j--;
	}
	cout<<cnt;
	return 0;
}
