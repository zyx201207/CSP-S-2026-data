#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long x;
	char c;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	int l=1,r=n;
	long long cnt=0;
	while(l<r){
		if(a[l].x==a[r].x&&a[l].c==a[r].c){
			l++;
			r--;
			continue;
		}
		if(a[l].x==a[r].x){
			cnt+=a[l].x;
			l++;
			r--;
			continue;
		}
		if(a[l].x>a[r].x){
			if(a[l].c!=a[r].c){
				cnt+=a[r].x;
			}
			a[l].x-=a[r].x;
			r--;
		}else{
			if(a[l].c!=a[r].c) {
				cnt+=a[l].x;
			}
			a[r].x-=a[l].x;
			l++;
		}
	}
	cout<<cnt;
	return 0;
}
