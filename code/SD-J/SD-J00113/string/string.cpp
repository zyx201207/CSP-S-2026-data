#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxx=2e5+10;
pair<long long,char>pa[maxx];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long i,n,ans=0;
	cin>>n;
	string s;
	for(i=1;i<=n;i++){
		cin>>pa[i].first>>pa[i].second;
		
	}
	long long l=1,r=n;
	while(l<r){
		if(pa[l].first<=pa[r].first){
			pa[r].first-=pa[l].first;
			if(pa[l].second!=pa[r].second){
				ans+=pa[l].first;
					
			}
			l++;
		}
		else{
			pa[l].first-=pa[r].first;
			if(pa[l].second!=pa[r].second){
				ans+=pa[r].first;
				
			}	
			r--;
		}
	}
	cout<<ans;
	return 0;
}
