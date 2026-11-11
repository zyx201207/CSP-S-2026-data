#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
long long a[N],n,m,b[N],c[N],ans=-1;
long long sum=0,len=0,l;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		c[i]=c[i-1]+b[i];
	}
	l=2;//Î¬»¤¶ÎÊý 
	for(int i=2;i<=n;i++){
		if(b[i]==0){
			len++;
			ans=max(ans,len+1);
			continue;//ans=len+1
		}
		if(sum+((len+1)*b[i])<=m){
			len++;
			sum+=((len)*b[i]);
			ans=max(ans,len+1);
		}
		else if(l!=i){
			len++;
			sum+=((len)*b[i]);
			while(sum>m && l!=i){
				len--;
				sum-=(c[i]-c[l-1]);
				l++;
			}
			if(l==i){
				cout<<ans;
				return 0;
			}
		}
		else{
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}//15:40 now:15:27   15:39

