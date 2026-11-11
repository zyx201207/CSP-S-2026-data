#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
long long ans;
struct node{
	int s;
	char c;
}a[200005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].s>>a[i].c;
	}
	int r=0,l=n-1;
	while(r!=l){
		if(a[r].c!=a[l].c){
			int m=min(a[r].s,a[l].s);
			ans+=m;
			a[r].s-=m;
			a[l].s-=m;
			if(a[r].s==0) r++;
			else l--;
		}else{
			int m=min(a[r].s,a[l].s);
			a[r].s-=m;
			a[l].s-=m;
			if(a[r].s==0) r++;
			else l--;
		}
	}
	cout<<ans;
	return 0;
}
