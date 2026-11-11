#include<bits/stdc++.h>
using namespace std;
int n,l,r;
long long ans;
struct node{
	int cnt;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n-1;
	for(int i=0;i<n;i++)cin>>a[i].cnt>>a[i].c;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].cnt>a[r].cnt){
				a[l].cnt-=a[r].cnt;
				r--;
			}else if(a[l].cnt<a[r].cnt){
				a[r].cnt-=a[l].cnt;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].cnt>a[r].cnt){
				ans+=a[r].cnt;
				a[l].cnt-=a[r].cnt;
				r--;
			}else if(a[l].cnt<a[r].cnt){
				ans+=a[l].cnt;
				a[r].cnt-=a[l].cnt;
				l++;
			}else{
				ans+=a[r].cnt;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
