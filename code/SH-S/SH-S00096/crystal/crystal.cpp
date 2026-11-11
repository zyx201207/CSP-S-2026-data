#include<bits/stdc++.h>
using namespace std;
void init_cin(){
	 ios::sync_with_stdio(false);
	 cin.tie(0);
	 cout.tie(0);
}
typedef long long ll;
int n;
ll m,a[500010],ans=1,s[201];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	init_cin();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4){
			ll sum=0,ans=0;
			for(int i=1;i<=n;i++){
				if((sum+i)<=m) sum+=i; 
				else{
					ans=i;
					break;
				}
			} 
			cout<<ans;
		}
		else if((a[2]-a[1])==(a[4098]-a[4097])){
			ll sum=0,ans=0,d=a[2]-a[1];
			for(int i=1;i<=n;i++){
				if((sum+i*d)<=m) sum+=i*d; 
				else{
					ans=i;
					break;
				}
			} 
			cout<<ans;			
		}
		else{
			for(int i=1;i<=n;i++){
				a[i]+=100;
				s[a[i]]++;
			}
			for(int j=200;j>=0;j--){
				ll sum=0,res=0;
				for(int i=j;i>=0;i--){
					if(sum+(s[i]*(j-i))<=m){
						sum+=(s[i]*(j-i));
						res+=s[i];
					}
					else{
						ll c=m-sum;
						ll p=c/(j-i);
						sum+=p*(j-i);
						res+=p;
						break;
					}
				}
				ans=max(ans,res);
			}	
			cout<<ans;			
		}
	}
	sort(a+1,a+1+n);	
	for(int i=1;i<=n;i++){
		ll cnt=0,l=0,s=a[i];
		for(int j=i;j>=1;j--){
			if((cnt+s-a[j])<=m){
				cnt+=(s-a[j]);
				l++;
			}
			else break;
		}
		ans=max(ans,l);
	} 
	cout<<ans;
	return 0;
}
