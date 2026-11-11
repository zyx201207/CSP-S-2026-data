#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int a;
	char c;
}s[N];
int n;
bool check(int x){
	int l=1,r=n;
	while(l<r){
		if((s[l].c!=s[r].c)||(s[l].a!=s[r].a)){
			x-=abs(s[l].a-s[r].a);
			if(s[l].a<s[r].a){
				s[r-1].a+=abs(s[l].a-s[r].a);
			}else{
			 	s[l+1].a+=abs(s[l].a-s[r].a);
			}
		}
		l++;
		r--;
	}
	return x>=0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f=false;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		if(s[i].c!=s[i+1].c&&i!=n){
			f=true;
		}
	}
	if(!f){
		cout<<0;
		return 0;
	}
	int l=1,r=1e9;
	int ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ans;
	return 0;
}