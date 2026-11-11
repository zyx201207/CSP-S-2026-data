#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct rj{
	ll num;
	char s;
};
rj l[100005],r[100005];
string tl,tr,a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll T,sum=0,i1=0;
	cin>>T;
	a=" "+a;
	bool f=0;
	char ls='0';
	while(T--){
		ll num;
		char s;
		cin>>num>>s;
		if(s!=ls){
			f=1;
		}
		ls=s;
		for(ll i=1;i<=num;i++){
			a+=s;
		}
	}
	if(f==0||T==1){
		cout<<0;
		return 0;
	}
	ll m=a.size();
	for(ll i=1;i<=a.size()/2;i++){
		if(a[i]!=a[m]){
			sum++;
		}
		m--;
	}
	cout<<sum;
//	ll js=i1;
//	i1=0;
//	if(sum%2!=0){
//		ll mid=sum/2+1,ls=0,rs=0;
//		ll midd=mid;
//		while(midd>0){
//			i1++;
//			ls++;
//			midd-=a[i1].num;
//			if(midd>=0){
//				l[i1].num=a[i1].num;
//				l[i1].s=a[i1].s;
//			}
//			else{
//				l[i1].num=a[i1].num+midd-1;
//				l[i1].s=a[i1].s;
//			}
//		}
//		r[1].num=a[i1].num-l[i1].num-1;
//		r[1].s=a[i1].s;
//		rs++;
//		ll now=1;
//		while(i1!=js){
//			i1++;
//			now++;
//			rs++;
//			r[now].num=a[i1].num;
//			r[now].s=a[i1].s;
//		}
//		if(l[ls].num==0){
//			ls--;
//		}
//		if(r[rs].num==0){
//			rs--;
//		}
////		for(ll i=1;i<=ls;i++){
////			cout<<l[i].num<<" "<<l[i].s<<endl;
////		}
////		cout<<endl;
////		for(ll i=1;i<=rs;i++){
////			cout<<r[i].num<<" "<<r[i].s<<endl;
////		}
//		ll k=1;
//		for(ll i=1;i<=ls;i++){
//			for(ll j=1;j<=l[i].num;j++){
//				tl+=l[i].s;
//			}
//		}
//		for(ll i=1;i<=rs;i++){
//			for(ll j=1;j<=r[i].num;j++){
//				tr+=r[i].s;
//			}
//		}
//		ll num=0;
//		for(ll i=0;i<tl.size();i++){
//			
//		}
//	}
//	else{
//		
//	}
	return 0; 
} 
