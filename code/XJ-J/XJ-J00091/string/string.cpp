#include<bits/stdc++.h>
using namespace std;
struct str{
	long long cnt;
	char c;
}a[200005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++){
		cin>>a[i].cnt>>a[i].c;
	}
	
	int l=0;
	int r=n-1;

	long long count=0;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].cnt>a[r].cnt){
				a[l].cnt-=a[r].cnt;
				a[r--].cnt=0;
			} else if(a[l].cnt==a[r].cnt){
				a[l++].cnt=0;
				a[r--].cnt=0;
			} else {
				a[r].cnt-=a[l].cnt;
				a[l++].cnt=0;
			}
		} else {
			if(a[l].cnt>a[r].cnt){
				count+=a[r].cnt;
				a[l].cnt-=a[r].cnt;
				a[r--].cnt=0;
			} else if(a[l].cnt==a[r].cnt){
				count+=a[r].cnt;
				a[l++].cnt=0;
				a[r--].cnt=0;
			} else {
				count+=a[l].cnt;
				a[r].cnt-=a[l].cnt;
				a[l++].cnt=0;
			}
		}
	}
	
	if(n==1){
		count=0;
	}
	cout<<count;
	return 0;
}
