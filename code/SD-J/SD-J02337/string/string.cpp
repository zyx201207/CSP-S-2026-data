#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
	}
	long long l=1,r=n,l1=1,r1=1;
	while(l<r){
		if(a[l].c!=a[r].c){
			ans+=min(a[l].a-l1+1,a[r].a-r1+1);
			l1+=min(a[l].a-l1+1,a[r].a-r1+1);
			r1+=min(a[l].a-l1+1,a[r].a-r1+1);
		}else{
			l1+=min(a[l].a-l1+1,a[r].a-r1+1);
			r1+=min(a[l].a-l1+1,a[r].a-r1+1);
		}
		if(l1>a[l].a){
			l++;
			l1=1;
		}
		if(r1>a[r].a){
			r--;
			r1=1;
		}
	}
	cout<<ans;
	return 0;
}
