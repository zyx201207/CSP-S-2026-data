#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt;
struct node{
	int x;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	} 
	int l=1,r=n;
	if(n==1){
		cout<<0;
		return 0;
	}
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].x==a[r].x){
				l++;
				r--;
			}	
			else if(a[l].x>a[r].x){
				a[l].x-=a[r].x;
				r--;
			}
			else{
				a[r].x-=a[l].x;
				l++;
			}
		}
		else{
			if(a[l].x==a[r].x){
				cnt+=a[l].x;
				l++;
				r--;
			}	
			else if(a[l].x>a[r].x){
				cnt+=a[r].x;
				a[l].x-=a[r].x;
				r--;
			}
			else{
				cnt+=a[l].x;
				a[r].x-=a[l].x;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

