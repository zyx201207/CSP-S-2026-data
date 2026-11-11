#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	//crystal
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0;cin>>n>>m;
	vector<long long> a(n);
	for(long long i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	long long p=0,q=0,cost=0,late;
	for(;p<n;p++){
	q=p+1;
	while(true){
		late=cost;cost=0;
		for(long long i=p;i<q;i++){
			cost+=a[q]-a[i];
		}
		if(cost>m) {
			break;
		}
		q++;
		if(q>=n) break;
	} 
	//cout<<ans<<" "<<p<<" "<<q<<endl;
	if(q-p>ans) ans=q-p;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
