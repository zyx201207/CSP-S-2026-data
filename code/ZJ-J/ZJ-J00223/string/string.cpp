#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200010];
struct node{
	ll point;
	char p;
	bool t;
}key[200010];
char c[200010];
char s[10000010];
bool cmp(node a,node b){
	return a.point<b.point;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	ll len=0;
	ll mx=0;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
		cin>>c[i];
		len+=a[i];
		mx=max(a[i],mx);
	}
	//if(mx>100000000){
		/*
	ll lenth=len;
	len/=2;
	bool is=0;
	for(int i=1;i<n;i++){
		if(a[i]<=len){
			key[i].point=a[i];
			key[i].p=c[i];
			key[i].t=1;
			if(a[i]<len){
				key[n+1].point=len;
				key[n+1].p=c[i+1];
				key[n+1].t=1;
			}
		}else if(a[i]>=n-len+1){
			if(is==0){
				is=1;
				key[n].point=len;
				key[n].p=c[i];
				key[n].t=0;
			}
			key[i].point=lenth-a[i];
			key[i].p=c[i+1];
			key[i].t=0;
		}
	}
	sort(key+1,key+n+2,cmp);
	n++;
	char up=' ';
	ll l=1,r=1;
	ll ans=0;
	
	while(l<=len,r<=len){
		if(key[r].t==1&&up==' '){
			up=key[r].p;
		}else if(up==' '){
			r++;
			continue;
		}
		if(key[l].t==0){
			l++;
			continue;
		}
		if(key[l].t==1){
			if(key[l].p!=up){
				sum+=key[l].point-min(key[l-1].l);
			}
			l++;
		}
		if()
	}	*/
	//}else{
		ll now=1;
		for(ll i=1;i<=a[n];i++){
			if(a[now]<i){
				now++;
			}
			s[i]=c[now];
		}
		ll sum=0;
		for(int i=1;i<=a[n]/2;i++){
			if(s[i]!=s[a[n]-i+1]){
				sum++;
			}
		}
		cout<<sum;
	//}
	return 0;
}