#include<bits/stdc++.h>
using namespace std;
struct str{
	long long x;
	string s;
}a[200005],l[200005],r[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].s;
		sum+=a[i].x;
	}
	long long ll=0,rr=0;
	bool lr=false; 
	if(sum%2==0){
		long long id=0;
		long long su=0;
		for(int i=0;i<n;i++){
			su+=a[i].x;
			if(su==sum/2){
				l[i].x=a[i].x;
				l[i].s=a[i].s;
				ll++;
				id=i+1;
				break;
			}else if(su>sum/2){
				lr=true;
				rr=1;
				a[i].x-=(su-sum/2);
				l[i].x=a[i].x;
				l[i].s=a[i].s;
				ll++;
				r[0].x=(su-sum/2);
				r[0].s=a[i].s;
				id=i+1;
				break;
			}
			l[i].x=a[i].x;
			l[i].s=a[i].s;
			ll++;
		}
		for(int i=0;i<n-ll;i++){
			if(lr){
				r[i+1].x=a[i+id].x;
				r[i+1].s=a[i+id].s;
				rr++;
			}else{
				rr++;
				r[i].x=a[i+id].x;
				r[i].s=a[i+id].s;
			}
		}
	}else{
		long long id=0;
		long long su=0;
		for(int i=0;i<n;i++){
			su+=a[i].x;
			if(su==sum/2){
				l[i].x=a[i].x-1;
				l[i].s=a[i].s;
				ll++;
				id=i+1;
				break;
			}else if(su>sum/2){
				lr=true;
				rr=1;
				a[i].x-=(su-sum/2);
				l[i].x=a[i].x;
				l[i].s=a[i].s;
				ll++;
				r[0].x=(su-sum/2)-1;
				r[0].s=a[i].s;
				id=i+1;
				break;
			}
			l[i].x=a[i].x;
			l[i].s=a[i].s;
			ll++;
		}
		for(int i=0;i<n-ll;i++){
			if(lr){
				r[i+1].x=a[i+id].x;
				r[i+1].s=a[i+id].s;
				rr++;
			}else{
				r[i].x=a[i+id].x;
				r[i].s=a[i+id].s;
				rr++;
			}
		}
	}
	long long cnt=0;
	long long lll=0,rrr=rr;
	for(long long i=0;;i++){
		if(lll>ll-1&&rrr<1){
			break;
		}
		if(l[lll].s==r[rrr].s){
			if(l[lll].x>=r[rrr].x){
				l[lll].x-=r[rrr].x;
				r[rrr].x=0;
				rrr--;
				continue;
			}else{
				r[rrr].x-=l[lll].x;
				l[lll].x=0;
				lll++;
				continue;
			}
		}else{
			if(l[lll].x>=r[rrr].x){
				l[lll].x-=r[rrr].x;
				cnt+=r[rrr].x;
				r[rrr].x=0;
				rrr--;
				continue;
			}else{
				r[rrr].x-=l[lll].x;
				cnt+=l[lll].x;
				l[lll].x=0;
				lll++;
				continue;
			}
		}
	}
	cout<<cnt;
	return 0;
}
