#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	int a;
	char x;
}p[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].x;
		len+=p[i].a;
	}
	int flag=0;
	if(len%2==0){
		flag=n/2;
	}else{
		flag=n/2+1;
	}
	int ans=0;
	int l=1,r=n;
	int ll=0,rr=0;
	bool left=1,right=1;
	while(ll<=flag&&rr<=flag){
		int cnt1=p[l].a,cnt2=p[r].a;
		char let1=p[l].x,let2=p[r].x;
		if(left){
			ll+=p[l].a;
			//cout<<"left\n";
		}
		if(right){
			rr+=p[r].a;
			//cout<<"right\n";
		}
		if(cnt1>cnt2){
			//cout<<"pwp\n";
			if(let1!=let2){
				//cout<<"qwq\n";
				ans+=cnt2;
			}
			p[l].a-=cnt2;
			left=0;
			right=1;
		}else{
			if(let1!=let2){
				ans+=cnt1;
			}
			p[r].a-=cnt1;
			if(cnt1==cnt2){
				left=1;
				right=1;
			}else{
				left=1;
				right=0;
			}
		}
		//cout<<"llrr "<<ll<<' '<<rr<<"\n";
		//cout<<"lr   "<<l<<' '<<r<<"\n";
		if(ll<rr){
			l++;
		}else if(ll>rr){
			r--;
		}else{
			l++;
			r--;
		}
		
		//cout<<ans<<"\n";
	}
	cout<<ans;
	return 0;
} 
/*
5
2 a
1 b
2 a
1 b
1 a
*/
