#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
struct node{
	int t;
	char c;
}a[M];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)cin>>a[i].t>>a[i].c;
	int l=1,r=n;
	while(l<=r){
		int t1=a[l].t,t2=a[r].t;
		char c1=a[l].c,c2=a[r].c;
		if(c1!=c2)ans+=min(t1,t2);
		if(t1>t2){
			a[l].t-=a[r].t;
			r--;
		}else if(t1<t2){
			a[r].t-=a[l].t;
			l++;
		}else l++,r--;
	}cout<<ans<<"\n";
	return 0;
}
