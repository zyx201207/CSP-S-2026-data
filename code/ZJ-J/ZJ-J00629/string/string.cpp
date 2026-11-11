#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,a[200005];
bool bo;
char ch[200005];
ll sum1,ans,sum[200005],la;
stack<pair<ll,char> > st1;
stack<pair<ll,char> > st2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char c;
		scanf("%d%c%c",&a[i],&c,&ch[i]);
		sum[i]=sum[i-1]+a[i];
		sum1+=a[i];
	}
//	la=sum1;
	sum1/=2;
//	cout<<sum1<<' '<<sth<<'\n';
//	cout<<"aabbc\n";
//	if(la<=2000000){
//		ll k=1;
//		int sth=lower_bound(sum+1,sum+n+1,sum1)-sum;
//		while(sum1-k>=1&&sum1+k<=la){
//		int it=lower_bound(sum+1,sum+n+1,sum1-k)-sum;
//		int l=1,r=n;
//		while(l<r){
//			int mi=(l+r)>>1;
//			if(sum[mi]>=sum1+k){
//				r=mi;
//			}
//			else{
//				l=mi+1;
//			}
//		}
//		if(ch[it]!=ch[r]){
//			ans++;
//		}
////		cout<<it<<' '<<r<<'\n';
//		k++;
//		}
//		printf("%lld",ans);
//		return 0;
//	}
	int sth_=lower_bound(sum+1,sum+n+1,sum1)-sum;
//	int sth_2=upper_bound(sum+1,sum+n+1,sum1)-sum;
	ll rig=sum[sth_]-sum1-(sum1%2);
	ll lef=sum1-sum[sth_-1];
	for(int i=n;i>=sth_+1;i--){
		st1.push({a[i],ch[i]});
	}
	st1.push({rig,ch[sth_]});
	for(int i=1;i<=sth_-1;i++){
		st2.push({a[i],ch[i]});
	}
	st2.push({lef,ch[sth_]});
	while(!st1.empty()&&!st2.empty()){
		pair<ll,char> no1=st1.top();
		pair<ll,char> no2=st2.top();
		st1.pop();
		st2.pop();
		if(no1.second==no2.second){
			if(no1.first>=no2.first){
				st1.push({no1.first-no2.first,no1.second});
			}
			else{
				st2.push({no2.first-no1.first,no1.second});
			}
		}
		else{
			if(no2.first>=no1.first){
				st2.push({no2.first-no1.first,no2.second});
				ans+=no1.first;
			}
			else{
				st1.push({no1.first-no2.first,no1.second});
				ans+=no2.first;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}//56pts
