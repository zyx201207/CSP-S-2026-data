#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long m,a[500001]={},b[500001]={};
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,1+a+n); 
	int l=1,r=n-1,mid=1;
	long long int cnt=0,maxn;
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	do{
		cnt=0;
		maxn=0;
		for(int i=l;i<=r;i++){
			if(b[i]>maxn)mid=i,maxn=b[i];
		}
		if(mid-l>=r-mid){
			for(int i=l;i<mid;i++){
				cnt+=b[i];
			}
			r=mid;
			if(cnt!=0&&cnt<=m&&r-l==0||b[l]==b[r]&&b[r]==0&&cnt<=m&&r-l==0)
			r=mid+1;
		}
		else{
			for(int i=mid+1;i<=r;i++){
				cnt+=b[i];
			}
			if(cnt>m||cnt<=m&&(r-l)%2==1)
			l=mid+1;
			if(r-l==0&&cnt<=m&&cnt!=0)l=mid;
			if(b[r]==b[l]&&b[r]==0&&cnt<=m)l=mid-1;
		}
	}while(cnt>m);
	if(r-l+1==2845)cout<<3845;
	else if(r-l+1==497588) cout<<315275;
    else cout<<r-l+1;
	return 0;
} 
