#include<bits/stdc++.h>
using namespace std;

int n;
int a[200010];
char c[200010];
long long ans,mid;
int yyz;
long long zwt;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ans+=a[i];
	}
	
	if(ans%2==0) mid=ans/2;
	else mid=ans/2+1;
	
	ans=0;
	for(int i=1;i<=n;i++){
		ans+=a[i];
		if(ans>mid){
			yyz=i;
			break;
		}
	}
	
	int l=1,r=n;
	while(l<yyz && yyz<=r){
		if(a[l]==0) l++;
		if(a[r]==0) r--;
		int mn=min(a[l],a[r]);
		if(c[l]!=c[r]) zwt+=mn;
		a[l]-=mn;
		a[r]-=mn;
	}
	
	cout<<zwt;
	return 0;
}

