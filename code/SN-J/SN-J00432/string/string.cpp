#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int a[200001];
char c[200001];
int s[200001];
bool check(int l,int r){
	if(n%2){
		return r-l>=1;
	}
	else{
		return r-l>=2;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			a[i]=0;
			c[i]=' ';
			n--;
			i--;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0;
			return 0;
		}
		cout<<min(a[1],a[2]);
		return 0;
	}
	int l=1,r=n;
	while(check(l,r)){
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
		}
		if(a[l]==a[r]){
			a[l]=a[r]=0;
			l++;
			r--;
			n-=2;
			continue;
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			a[r]=0;
			r--;
			n--;
			continue;
		}
		if(a[l]<a[r]){
			a[r]-=a[l];
			a[l]=0;
			l++;
			n--;
		}
	}
	if(n%2){
		cout<<ans;
		return 0;
	}
	if(c[l]==c[r]){
		cout<<0;
		return 0;
	}
	cout<<ans+min(a[l],a[r]);
	return 0;
}
/*
T2 probably idk pts
This is too bad I hate that
Had very not clever problems lol
Idk how fast it is
But computers are fast nowadays
So I think this program can 100pts
100pts pls I say
Okay I tested the large datas and it ran so fast and correctly
This may be 100pts solution I think
if less than 100pts I can say nothing...
*/
