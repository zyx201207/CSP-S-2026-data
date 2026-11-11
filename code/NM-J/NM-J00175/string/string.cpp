#include<bits/stdc++.h>
using namespace std;
struct A{
	int num;
	char name;
}a[100005];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,nnum=0,k,l=0,r=0;
	char tl,tr;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i].num>>a[i].name;
		nnum+=a[i].num;//13
	}
	k=nnum;//13
	int ll=0,rr=0;
	while (!(ll+a[l].num>nnum/2 && rr+a[r].num>nnum/2) ){
		if(ll<=rr) {
			ll+=a[l].num;//3 5 
			tl=a[l].name;//a b 
			l++;
		}
		if(ll>=rr){
			rr+=a[n-r].num;//3 6
			tr=a[n-r].name;//a c
			r++;
		}
		if(tl==tr) {
			k=k-(min(ll,rr)-max(ll-a[l-1].num,rr-a[r-1].num));//10
		}
	}
	k=k-min(nnum-ll,nnum-rr);
	int jkl=min(nnum-ll,nnum-rr)-k;
	if(jkl%2==1){
		jkl--;
	}
	cout<<abs(jkl);
	return 0;
}

