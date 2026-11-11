#include<bits/stdc++.h>
using namespace std;
struct node{
	long long cnt;
	char ch;
};
long long n,ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	vector<node>b(n);
	for(long long i=0;i<n;i++){
		cin>>b[i].cnt>>b[i].ch;
	}
	long long lb=0,rb=n-1;
	long long lr=b[lb].cnt;
	long long rr=b[rb].cnt;
	while(lb<rb){
		long long t=min(lr,rr);
		if(b[lb].ch!=b[rb].ch){
			ans+=t;
		}
		lr+=t;
		rr-=t;
		if(lr==0){
			lb++;
			lr=b[lb].cnt;
		}
		if(rr=0){
			rb++;
			rr=b[rb].cnt;
		}
	}
	cout<<ans-3;
	return 0;
}
