#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
ll n,x,sum=0,ans=0,ma=0;
string s;
int a[200010],b[200010];
char d,c[200010],r[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cin>>x>>s;
		cout<<0;
		return 0;
	}else if(n<=2000){
		for(int i=1;i<=n;i++){
			cin>>a[i]>>d,sum+=a[i],x=a[i];
			for(int i=1;i<=x;i++) s+=d;
		} 
		sum=(sum)/2,s=" "+s;
		for(int i=1;i<=sum;i++) if(s[i]!=s[2*sum-i+1]) ans++; 
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i]>>c[i];
			sum+=a[i];
		}
		for(int i=1;i<=n;i++){
			b[i]=a[n-i+1];
			r[i]=c[n-i+1];
		}
		for(int i=1;i<=n;i++){
			ma+=a[i];
			if(ma>sum) break;
			if(r[i]!=c[i]){
				ans+=min(b[i],a[i]);
			}
		}
		ans/=2;
	}
	cout<<ans;
	return 0;
}
/*
2
2 a
3 a
out 0;
3
2 a
2 b
1 c
out 2;
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
32-40 pts
*/
