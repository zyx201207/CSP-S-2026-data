#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+7;
struct node{
	ll cnt;
	char s;
}l[N],r[N];
int n;
ll a[N];
int tl,tr;
char s[N];
ll sum=0,ans=0;
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	ll res=0;
	for(int i=1;i<=n;i++){
		if(res+a[i]>sum/2){
			ll tmp=sum/2-res;
			if(tmp!=0)l[++tl]={tmp,s[i]};
			break;
		}
		l[++tl]={a[i],s[i]};
		res+=a[i];
	}
	res=0;
	for(int i=n;i>=1;i--){
		if(res+a[i]>sum/2){
			ll tmp=sum/2-res;
			if(tmp!=0)r[++tr]={tmp,s[i]};
			break;
		}
		r[++tr]={a[i],s[i]};
		res+=a[i];
	}
	for(int i=1,j=1;i<=tl&&j<=tr;){
		if(l[i].cnt>r[j].cnt){
			l[i].cnt-=r[j].cnt;
			ans+=(l[i].s==r[j].s)?0:r[j].cnt;
			j++;
		}else if(r[j].cnt>l[i].cnt){
			r[j].cnt-=l[i].cnt;
			ans+=(l[i].s==r[j].s)?0:l[i].cnt;
			i++;
		}else {
			ans+=(l[i].s==r[j].s)?0:l[i].cnt;
			i++;j++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
