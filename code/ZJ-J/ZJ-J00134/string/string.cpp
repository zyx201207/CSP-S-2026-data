#include<bits/stdc++.H>
using namespace std;
int n;
int a[200007][3];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char p1;
		cin>>a[i][1];
		cin>>p1;
		a[i][2]=(int)(p1-'a'+1);
	}
	int l=1,r=n;
	while(l!=r){
		if(a[l][2]!=a[r][2]){
			ans+=min(a[l][1],a[r][1]);
		}
		long long p=min(a[l][1],a[r][1]);
		a[l][1]-=p;
		a[r][1]-=p;
		if(a[l][1]==0)l++;
		if(a[r][1]==0)r--;
	}
	cout<<ans;
	return 0;
}