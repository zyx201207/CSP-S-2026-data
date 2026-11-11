#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
pair<long long,char>b[N+5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>b[i].first>>b[i].second;
		
	}
	long long l=1,r=n,ans=0;
	while(l<r){
		if(b[l].second==b[r].second){
			long long e=min(b[l].first,b[r].first);
			if(b[l].first-e==0)l++;
			else b[l].first-=e;
			if(b[r].first-e==0)r--;
			else b[r].first-=e;
		}
		else{
			long long e=min(b[l].first,b[r].first);
			ans+=e;
			if(b[l].first-e==0)l++;
			else b[l].first-=e;
			if(b[r].first-e==0)r--;
			else b[r].first-=e;
		}
	} 
	cout<<ans<<endl;
	return 0;
} 
