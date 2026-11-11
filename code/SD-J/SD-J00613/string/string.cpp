#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}a[200005];
int n;
long long sum=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		sum+=a[i].a;
	}
	int l=1,r=n,x=min(a[1].a,a[n].a);
	long long lpos=0,rpos=0;
	while(lpos+rpos<sum){
		lpos+=a[l].a;
		rpos+=a[r].a;
		if(a[l].c!=a[r].c){
			ans+=x;
		}
		x=abs(lpos-rpos);
		if(lpos<rpos) l++;
		else if(lpos>rpos) r--;
		else{
			l++,r--;
			x=min(a[l].a,a[r].a);
		}
	}
	cout<<ans;
	return 0;
}
