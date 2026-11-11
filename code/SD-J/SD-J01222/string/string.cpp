#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct node{
	int number;
	char c;
}a[200005];
int n,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].number>>a[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c!=a[r].c){
			ans+=min(a[r].number,a[l].number);
		}
		if(a[r].number<a[l].number){
			a[l].number-=a[r].number;r--;
		}else{
			a[r].number-=a[l].number;l++;
		}
	}
	cout<<ans;
	return 0;
}

