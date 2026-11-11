#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	vector<pair<long long,char> >a(n);
	for(long long i=0;i<n;i++){
		long long x;
		char y;
		cin>>x>>y;
		a[i]={x,y};
	}
	long long l=0;
	long long r=n-1;
	long long ll=a[l].first;
	long long rl=a[r].first;
	long long res=0;
	while(l<r){
		if(ll>rl){
			if(a[l].second!=a[r].second){
				res+=rl;
			}
			ll-=rl;
			r--;
			rl=a[r].first;
		}
		else if(ll<rl){
			if(a[l].second!=a[r].second){
				res+=ll;
			}
			rl-=ll;
			l++;
			ll=a[l].first;
		}
		else{
			if(a[l].second!=a[r].second){
				res+=ll;
			}
			l++;
			ll=a[l].first;
			r--;
			rl=a[r].first;
		}
	}
	cout<<res<<endl;
	return 0;
}
