#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2e5+5;
vector<int> v[30],v1[30];
struct node{
	int l,r,cnt;
	char c;
}a[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,lst=0,sum=0;
	cin>>n;
	int id=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
		a[i].l=lst+1;
		a[i].r=a[i].l+a[i].cnt-1;
		sum+=a[i].cnt;
		lst=a[i].r;
	}
	if(sum%2==0){
		int ans=0;
		int len=sum/2,x,q;
		bool f=0;
		for(int i=1;i<=n;i++){
			if(a[i].r<=len) x=i,v1[a[i].c-'a'].push_back(i);
			if(a[i].l>len) v[a[i].c-'a'].push_back(i);
			if(a[i].l<=len&&a[i].r>len) f=1,q=i;
		}
		for(int i=1;i<=x;i++){
			for(auto k:v[a[i].c-'a']){
				int L=max(a[k].l,sum+1-a[i].r);
				int R=min(a[k].r,sum+1-a[i].l);
				ans+=R-L+1;
			}
		}
		if(f==1){
			int lenl=len-a[q].l+1,lenr=a[q].cnt-lenl;
			ans+=min(lenl,lenr);
			if(lenl>lenr){
				for(auto k:v[a[q].c-'a']){
					int L=max(a[k].l,sum+1-(a[q].r-2*lenr));
					int R=min(a[k].r,sum+1-a[q].l);
					ans+=R-L+1;
				}
			}
			else if(lenl<lenr){
				for(auto k:v1[a[q].c-'a']){
					int L=max(a[k].l,sum+1-a[q].r);
					int R=min(a[k].r,sum+1-(a[q].l+lenl*2));
					if(L>R) continue;
					ans+=R-L+1;
				}
			}
		}
		cout<<len-ans;
	}
	else{
		int ans=0;
		int len=sum/2+1,x,q;
		bool f=0;
		for(int i=1;i<=n;i++){
			if(a[i].r<len) x=i,v1[a[i].c-'a'].push_back(i);
			if(a[i].l>len) v[a[i].c-'a'].push_back(i);
			if(a[i].l<=len&&a[i].r>=len) f=1,q=i;
		}
		for(int i=1;i<=x;i++){
			for(auto k:v[a[i].c-'a']){
				int L=max(a[k].l,sum+1-a[i].r);
				int R=min(a[k].r,sum+1-a[i].l);
				ans+=R-L+1;
			}
		}
		if(f==1){
			int lenl=len-a[q].l,lenr=a[q].r-len;
			ans+=min(lenl,lenr);
			if(lenl>lenr){
				for(auto k:v[a[q].c-'a']){
					int L=max(a[k].l,sum+1-(a[q].r-2*lenr));
					int R=min(a[k].r,sum+1-a[q].l);
					ans+=R-L+1;
				}
			}
			else if(lenl<lenr){
				for(auto k:v1[a[q].c-'a']){
					int L=max(a[k].l,sum+1-a[q].r);
					int R=min(a[k].r,sum+1-(a[q].l+lenl*2));
					if(L>R) continue;
					ans+=R-L+1;
				}
			}
		}
		cout<<len-ans-1;
	}
	return 0;
}