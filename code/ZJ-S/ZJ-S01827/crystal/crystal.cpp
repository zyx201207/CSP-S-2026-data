#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ma=-1,cnt=0,sum=0;
deque<long long> d;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(d.size()){
			long long g=d.back();
			sum+=cnt*(a[i]-g);
		}
		cnt++;
		d.push_back(a[i]);
		while(sum>m){
			long long t=d.front(),p=d.back();
			d.pop_front();
			sum-=p-t;
			cnt--;
		}
		ma=max(cnt,ma);
	}
	cout<<ma;
	return 0;
}