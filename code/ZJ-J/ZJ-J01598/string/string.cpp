#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
	LL m;
	char ch;
};
node a[200005];
LL n,l,r,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].ch;
	}
	l=1;
	r=n;
	while(l<=r){
		if(a[l].ch==a[r].ch){
			if(a[l].m==a[r].m){
				l++;
				r--;
			}
			else if(a[l].m>a[r].m){
				a[l].m-=a[r].m;
				r--;
			}
			else{
				a[r].m-=a[l].m;
				l++;
			}
		}
		else{
			if(a[l].m==a[r].m){
				ans+=a[l].m;
				l++;
				r--;
			}
			else if(a[l].m>a[r].m){
				ans+=a[r].m;
				a[l].m-=a[r].m;
				r--;
			}
			else{
				ans+=a[l].m;
				a[r].m-=a[l].m;
				l++;
			}			
		}
	}
	cout<<ans;
	return 0;
}
