#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using Pii=pair<int,int>;
using _i128=__int128;
using ull=unsigned long long;
const int maxN=5e5+10;
_i128 qread(){
	_i128 sum=0;
	char ch=getchar();
	bool flag=1;
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-'){
		flag=0;
		ch=getchar();
	} 
	while(isdigit(ch)) 
		sum=sum*10+(ch-'0'),ch=getchar();
	return sum*(flag==1?1:-1);
}
void qprint(_i128 x){
	if(x==0) return;
	if(x<0){
		cout<<'-';
		x=-x;
	} 
	int g=x%10;
	qprint(x/10);
	cout<<g;
}
LL n;
_i128 m,a[maxN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;
	m=qread();
//	qprint(m);cout<<'\n';
	_i128 ans=1;
	for(int i=1;i<=n;i++) a[i]=qread();
	sort(a+1,a+n+1);
//for(int i=1;i<=n;i++){
//	qprint(a[i]);
//	cout<<' ';
//} 
//cout<<'\n';
	_i128 sum=0;
	int l=1,r=1;
	int t=0;
	while(l<n&&r<n&&l<=r){
//cout<<l<<' '<<r<<'-'<<sum<<'\n';
		r++;
		_i128 cnt=r-l+1;
		sum+=(a[r]-a[r-1])*(cnt-1);
		if(sum<=m){
			ans=max(ans,cnt);
		}
		else{
			while(sum>m){
				sum-=(a[r]-a[l]);
				l++;
			}
			cnt=r-l+1;
			ans=max(ans,cnt);
		}
	}
//cout<<l<<' '<<r<<'-'<<sum<<'\n';
	qprint(ans);
	return 0;
}

