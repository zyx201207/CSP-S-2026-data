#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+300;
int n,cnt,ans;
char c;
pair<int,char>a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int x,i=1;i<=n;i++){
		cin>>x>>c;
		a[i].first=x;
		a[i].second=c;
		cnt+=x;	
	}int l=1,r=n;
	while(l<=r){
		if(a[l].first==a[r].first){
			if(a[l].second==a[r].second){
				l++;
				r--;
				continue;
			}else{
				ans+=a[l].first;
				l++;
				r--;
				continue; 
			}
		}else if(a[l].first>a[r].first){
			if(a[l].second==a[r].second){
				a[l].first-=a[r].first;
				r--;
				continue;
			}else{
				a[l].first-=a[r].first;
				ans+=a[r].first;
				r--;
				continue; 
			}
		}else if(a[l].first<a[r].first){
			if(a[l].second==a[r].second){
				a[r].first-=a[l].first;
				l++;
				continue;
			}else{
				a[r].first-=a[l].first;
				ans+=a[l].first;
				l++;
				continue; 
			}
		}
	}
	cout<<ans;
	return 0;
}
