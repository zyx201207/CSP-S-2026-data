#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=2*1e5;
const int N=114514;
ll maxn=-1;
ll n,m;
ll a[M];
ll choose[M];
void f(int x,int mm,int j){
	if(mm==0){
		return;
	} 
	for(int i=x;i<=n;i++){
		choose[j]=i;
		f(i,mm-1,j+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	ll ans=0;
	if(m==1){
		cout<<maxn;
	}else if(m==n){
		ans=a[1];
		for(ll i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}else if(m==2){
		maxn=-1;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(a[i]&a[j]>maxn){
					maxn=a[i]&a[j];
				}
			}
		}
		cout<<maxn;
	}else{
		maxn=-1;
		for(int j=1;j<=n;j++){
//			for(int k=1;k<=n;k++){
				f(j,m,1);
//			}
			ans=choose[1];
			for(int i=2;i<=m;i++){
				ans=ans&choose[i]; 
			}
			if(ans>maxn){
				maxn=ans;
			}
		}
		cout<<maxn+2;
	}
	return 0;
} 
