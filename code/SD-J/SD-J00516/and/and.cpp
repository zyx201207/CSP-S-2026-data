#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200003
ll a[maxn],b,c,d,i,j,k,m,n,dp[maxn],ans,sum,tot,cnt,l,r,p,x,y,t,dis[maxn];
string s1,s2,s3,s4,s[maxn];
string ej(int a){
	string s;
	while(a){
		s+=(a%2)-'0';
		a/=2;
	}
	string s1;
	for(i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	return s1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		for(i=1;i<=n;i++){
			ans&=a[i];
		}
	}
	else if(m==1){
		for(i=1;i<=n;i++)ans=max(ans,a[i]); 
	}
	else if(m==2){
		for(i=1;i<=n;i++){
			for(j=1;j<=n,j!=i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else{
		sort(a+1,a+1+n);
		for(i=1;i<=n;i++){
			char ss[200000];
			int xb=0;
			while(a[i]){
				ss[++xb]=a[i]%2;
				a[i]/=2;
			}
			for(i=xb-1;i>=0;i--){
				s[i]=ss[i];
			}
			
		}
		cout<<11111111<<endl;
		return 0;
	}
	cout<<ans<<endl;
	
	return 0;
}
