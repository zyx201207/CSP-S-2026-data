#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
int n,m;
int k;
int maxi=-1e18;
int ans=1;
int st,en;
int a[N];
int b[N];
map<int,int> mp;
bool ff=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	int mid=n/2;
	k=m;
	st=mid,en=mid;
	for(int i=mid-1;i>=1;i--){
		if(abs(a[i]-a[mid])<=k){
			k-=abs(a[i]-a[mid]);
			ans++;
			st=i;
		}else{
			break;
		}
	}
	for(int i=mid+1;i<=n;i++){//Ê£ÏÂµÄÌîÓÒ±ß 
		if(ans*abs(a[i]-a[mid])<=k){
			k-=ans*abs(a[i]-a[mid]);
			a[mid]=a[i];
			ans++;
			en=i;
		}else{
			break;
		}
	}
	for(int i=st;i<=en;i++){
		a[i]=a[mid];
	}
//	cout<<st<<' '<<en;
	ans=0;
	for(int i=1;i<=n;i++){
//			cout<<a[i]<<' ';
		if(a[i]==a[mid]){
			ans++;
		}
	}
//	cout<<endl;
	maxi=max(maxi,ans);
	
	for(int i=1;i<=n;i++){
		a[i]=b[i];
	}
	k=m;
	st=mid,en=mid;
	ans=1;
	for(int i=mid+1;i<=n;i++){
		if(ans*abs(a[i]-a[mid])<=k){
			k-=ans*abs(a[i]-a[mid]);
			a[mid]=a[i];
			ans++;
			en=i;
		}else{
			break;
		}
	}
	for(int i=mid-1;i>=1;i--){//Ê£ÏÂµÄÌî×ó±ß 
		if(abs(a[i]-a[mid])<=k){
			k-=abs(a[i]-a[mid]);
			ans++;
			st=i;
		}else{
			break;
		}
	}
	for(int i=st;i<=en;i++){
		a[i]=a[mid];
	}
	ans=0;
	for(int i=1;i<=n;i++){
//			cout<<a[i]<<' ';
		if(a[i]==a[mid]){
			ans++;
		}
	} 
//	cout<<endl;
	maxi=max(maxi,ans);
	cout<<maxi;
	
	return 0; 
}
/*
184726
313324 1 313324 198717 7833100

5 5
1 2 4 8 9
*/
