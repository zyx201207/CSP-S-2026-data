#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	long long num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n;
	long long sl=a[1].num,sr=a[n].num;
	while(l<r){
		if(a[l].c!=a[r].c) ans+=min(sl,sr);
		if(sl>sr){
			r--;
			sl-=sr;
			sr=a[r].num;
		}
		else if(sl<sr){
			l++;
			sr-=sl;
			sl=a[l].num;
		}
		else{
			l++;
			r--;
			sl=a[l].num;
			sr=a[r].num;
		}
	}
	cout<<ans;
	return 0;
}
