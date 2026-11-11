#include<bits/stdc++.h>
using namespace std;
struct node{
	string name;
	int cnt;
}p[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].cnt>>p[i].name;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		//cout<<l<<" "<<r<<endl;
		if(p[l].cnt==0){
			l++;
		}
		if(p[r].cnt==0){
			r--;
		}
		int k=min(p[l].cnt,p[r].cnt);
		if(p[l].name!=p[r].name){
			ans+=k;
		}
		if(p[l].cnt>=p[r].cnt){
			p[l].cnt-=p[r].cnt;
			p[r].cnt=0;
		}else{
			p[r].cnt-=p[l].cnt;
			p[l].cnt=0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
