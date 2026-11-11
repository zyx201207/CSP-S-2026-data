#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,T,x,ans,k;
struct node{
	char s;
	int num;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].num>>a[i].s;
	for(int i=1,j=n;i<=j;i++){
		if(a[i].s==a[j].s){
			if(a[i].num>a[j].num){
				a[i].num-=a[j].num;
				j--;
				i--;
			}
			else a[j].num-=a[i].num;
		}
		else{
			ans+=a[i].num;
			if(a[i].num<a[j].num) a[j].num-=a[i].num;
			else{
				k=a[i].num-a[j].num;
				j--;
				while(k>=a[j].num){
					k-=a[j].num;
					if(a[j].s==a[i].s) ans-=a[j].num;
					j--;
				}
				if(a[j].s==a[i].s) ans-=k;
				a[j].num-=k;
			}
		}
	}
	cout<<ans;
	return 0;
}
