#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
ll n,m,a[maxn],dl=0,dr=0,cl,cr,l,r,nl,nr;
void f(ll mid){
	dl=dr=0;
	cl=cr=0;
	for(int i=nl;i<=nr;i++){
		if(a[i]<=mid) {
			cl++;
			dl+=mid-a[i];
		}
		else if(a[i]>mid){
			cr++;
			dr+=a[i]-mid;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	l=a[0],r=a[n-1];
	nl=0,nr=n-1;
	ll mid;
	while(l+1<r&&nl<nr){
		mid=(l+r)/2;
		f(mid);
		if(dl==m){
			cout<<cl;
			return 0;
		}
		if(dr==m){
			cout<<cr+1;
			return 0;
		}
		if(dl>m&&dr>m){
			if(dl>dr){
				r=mid;
				nr=nr-cr;
			}
			else{
				l=mid+1;
				nl=nl+cl;
			}
		}
		if(dl<m&&dr<m){
			if(dl<dr){
				r=mid;
				nr=nr-cr;
			}
			else{
				l=mid+1;
				nl=nl+cl;
			}
		}
	}
	cout<<max(dl,dr);
	return 0;
}