#include<bits/stdc++.h>
using namespace std;
long long a[555555];
map<long long,bool>mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,l,r,sum,s,ans=0;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		l=i;
		r=i;
		s=a[i];
		sum=1;
		if(mp[s])continue;
		mp[s]=1;
		while(1){
			if(l-1<1&&r+1>n)break;
			if(l-1<1){
				if(m-(a[r+1]-s)*sum>=0){
					m-=(a[r+1]-s)*sum;
					r++;
					s=a[r];
					sum++;
				}else break;
			}else if(r+1>n){
				if(m-(s-a[l-1])>=0){
					m-=s-a[l-1];
					l--;
					sum++;
				}else break;
			}else{
				if((a[r+1]-s)*sum>=s-a[l-1]){
					if(m-(s-a[l-1])>=0){
						m-=s-a[l-1];
						l--;
						sum++;
					}else break;
				}else{
					if(m-(a[r+1]-s)*sum>=0){
						m-=(a[r+1]-s)*sum;
						r++;
						s=a[r];
						sum++;
					}else break;
				}
			}
		}
		if(sum>=ans)ans=sum;
	}
	cout<<ans;
	return 0;
}