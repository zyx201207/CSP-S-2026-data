#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n;
struct node{
	long long k;
	char s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long q;
	char p;
	cin>>a[1].k>>a[1].s;
	long long t=2;
	for(long long i=2;i<=n;i++){
		cin>>q>>p;
		if(p==a[t-1].s){
			a[t-1].k+=q;
		}
		else{
			a[t].k=q;
			a[t++].s=p;
		}
	}
	t--;
	if(t==1){
		cout<<0;
		return 0;
	}
	if(t==2){
		cout<<min(a[1].k,a[2].k);
		return 0;
	}
	long long l=1,r=t,sum=0,c;
	while(l<=r-1){
		if(a[l].s!=a[r].s){
			sum+=min(a[l].k,a[r].k);
		}
		else if(a[l].k==a[r].k){
			l++,r--;
			continue;
		}
		else{
			c=abs(a[l].k-a[r].k);
			sum+=c;
		}
		if(a[l].k<a[r].k){
			l++;
			a[r].s=a[l].s;
			a[r].k=c;
		}
		else if(a[l].k>a[r].k){
			r--;
			a[l].s=a[r].s;
			a[l].k=c;
		}	
	}
	cout<<sum;
	return 0;
}
