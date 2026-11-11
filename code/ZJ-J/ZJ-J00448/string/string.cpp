#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long a;
	char c;
}p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].c;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
    int l1=1,r1=n;
	long long ans=0;	
	while(l1<=r1){
		long long t=min(p[l1].a,p[r1].a);
		if(p[l1].c!=p[r1].c){
			ans+=t;
		}
		if(p[l1].a<p[r1].a){
			p[r1].a-=t;
			l1++;
		}
		else if(p[l1].a>p[r1].a){
			p[l1].a-=t;
			r1--;
		}
		else{
			l1++;
			r1--;
		}
	}
	cout<<ans;
	return 0;
}
