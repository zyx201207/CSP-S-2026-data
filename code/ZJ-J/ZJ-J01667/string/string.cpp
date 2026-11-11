#include<bits/stdc++.h>
using namespace std;
pair<long long,char> a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	for(int i=1;i<=n;i++){
		a[i].first+=a[i-1].first;
	}
	int kl=1,kr=n;
	long long l=0,r=a[n].first;
	while(l<r){
		if(l<0||r>2e14)break;
		if(a[kl].first-l==r-a[kr-1].first){
			if(a[kl].second!=a[kr].second)ans+=a[kl].first-l;
			l=a[kl].first+1;r=a[kr-1].first-1;
			kl++,kr--;
			//cout<<"a "<<l<<' '<<r<<' '<<ans<<' ';
		}
		else if(a[kl].first-l<r-a[kr-1].first){
			if(a[kl].second!=a[kr].second)ans+=a[kl].first-l;
			l=a[kl].first+1;r-=a[kl].first-l+1;
			kl++;
			//cout<<"b "<<l<<' '<<r<<' '<<ans<<' ';
		}
		else if(a[kl].first-l>r-a[kr-1].first){
			if(a[kl].second!=a[kr].second)ans+=r-a[kr-1].first;
			l+=r-a[kr].first+1;r=a[kr].first-1;
			kr--;
			//cout<<"c "<<l<<' '<<r<<' '<<ans<<' ';
		}
	}
	cout<<ans;
	return 0;
} 
