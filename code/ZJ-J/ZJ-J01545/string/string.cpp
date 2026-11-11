#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct Node{
	int num;
	char c;
}a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n,ans=0;
	while(l<r){
		if(a[l].c!=a[r].c) ans+=min(a[l].num,a[r].num);
		if(a[l].num<a[r].num) a[r].num-=a[l].num,l++;
		else{
			a[l].num-=a[r].num;
			r--;
			if(a[l].num==0) l++;
		}
	}
	cout<<ans;
    return 0;
}
