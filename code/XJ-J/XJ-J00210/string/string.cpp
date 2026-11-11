#include<algorithm>
#include<cmath>
#include<string>
#include<deque>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
struct node{
	long long s;
	char c;
}a[200005];
long long li=0,ri=0,sum=0;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=1,r;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	r=n;
	li=a[1].s;
	ri=a[n].s;
	while(l<=r){
		if(li>ri){
			li-=ri;
			if(a[l].c!=a[r].c) ans+=ri;
			r--;
			ri=a[r].s;
		}
		else if(li<ri){
			ri-=li;
			if(a[l].c!=a[r].c) ans+=li;
			l++;
			li=a[l].s;
			
		}
		else{
			if(a[l].c!=a[r].c) ans+=li;
			l++,r--;
			ri=a[r].s;
			li=a[l].s;
		}
		if(l==r){
			break;
		}
	}
	cout<<ans;
	return 0;
}

