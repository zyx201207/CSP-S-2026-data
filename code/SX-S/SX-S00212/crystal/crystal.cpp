#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 500010
ll n,m,mm,a[MAXN],c,t=1,t1,t2,j[MAXN];
/*struct node{
	ll w;
	ll h;
};
bool cmp(node a,node b){
	if(a.w!=a.h)return a.w>b.w;
	return a.h<b.h;
}
*/
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		mm=m;
		if(a[i]>=0&&a[i-1]>=0){
			if(a[i+1]-a[i]>=0){
				if(mm-((a[i+1]-a[i])*t)>=0){
					mm-=(a[i+1]-a[i])*t;
					t+=1;
				}else{
					break;
				}
			}else{
				if(mm-((a[i]-a[i+1])*t)>=0){
					mm-=(a[i]-a[i+1])*t;
					t+=1;
				}else{
					break;
				}
			}
		}else{
			if(a[i+1]<0){
				if(mm+((a[i+1]-a[i])*t)>=0){
					mm+=(a[i+1]-a[i])*t;
					t+=1;
				}else{
					break;
				}
			}else{
				if(mm+((a[i]-a[i+1])*t)>=0){
					mm+=(a[i]-a[i+1])*t;
					t+=1;
				}else{
					break;
				}
		}
	}
}
	/*
	sort(a,a+n);
	for(ll mi=1;mi<n;mi++){
		t1==0;
		mm=m;
		for(ll i=mi-1;i>=0;i--){
			if(mm-(a[mi]-a[i])>=0&&i>0){
				mm-=(a[mi]-a[i]);
				t1+=1;
			}else{
				break;
			}
		}
  		cout<<t1;
  		if(t2+t1>m){
			continue;
			t[mi]=t2;
		}else{
			t2+=t1;
		}

	}

	sort(t+1,t+n-1);
	for(int i=1;i<n;i++){
		cout<<t[i];
	}
	/*
	for(ll i=1;i<n;i++){
		mm[i]=0;
		for(ll ans=1;mm[i]<m;ans++){
			if(mm[i]+=a[i]-a[i-ans]<=m&&i-ans>=0){
				mm[i]+=a[i]-a[i-ans];
				t1[i]+=1;
				cout<<t1[i]<<" ";
			}else{
				break;
			}

		}
	}*/
	cout<<t;
	return 0;
}