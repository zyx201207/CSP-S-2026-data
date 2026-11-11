#include <bits/stdc++.h>
using namespace std;
struct P{
	string s;
	long long st,ed;
}a[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long p=1;
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		cin>>a[i].s;
		a[i].st=p;
		a[i].ed=a[i].st+x-1;
		p=a[i].ed+1;
	}
	long long sum=0;
	long long l=1,r=a[n].ed;
	long long lw=1,rw=n;
	while(l<=r){
		int flag=0;//0:same 1:different
		if(a[lw].s!=a[rw].s){
			sum++;
			flag=1;
		}
		l++,r--;
		if(l>a[lw].ed){
			lw++;
		}
		else if(r<a[rw].st){
			rw--;
		}
		else{
			int q=min((a[lw].ed-l),(r-a[rw].st))+1;
			l+=q;
			r-=q;
			sum+=q*flag;
		}
	}
	cout<<sum;
	return 0;
}