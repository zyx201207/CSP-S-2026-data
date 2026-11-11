#include<bits/stdc++.h>
using namespace std;
int n;long long int ans;
struct node{
	int val;char ch;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].val>>a[i].ch;
	int l=1,r=n;
	while(l<r){
		if(a[l].ch==a[r].ch){
			if(a[l].val>a[r].val){
				a[l].val-=a[r].val;
				r--;
			}
			else if(a[l].val==a[r].val){
				l++;r--;
			}
			else{
				a[r].val-=a[l].val;
				l++;
			}
		}
		else{
			ans+=min(a[l].val,a[r].val);
			if(a[l].val>a[r].val){
				a[l].val-=a[r].val;
				r--;
			}
			else if(a[l].val==a[r].val){
				l++;r--;
			}
			else{
				a[r].val-=a[l].val;
				l++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}