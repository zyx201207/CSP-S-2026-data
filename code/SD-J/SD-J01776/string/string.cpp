#include<bits/stdc++.h>
#define ll long long
#define mes(a,b) memset(a,b,sizeof a);
using namespace std;
const int N=2e5+10;
struct node{
	ll t;
	char ch;
}a[N];
int n;
ll sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].t>>a[i].ch;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].ch!=a[r].ch){
			if(a[l].t>a[r].t){
				ans+=a[r].t;
				a[l].t-=a[r].t;
				r--;
			}else if(a[l].t<a[r].t){
				ans+=a[l].t;
				a[r].t-=a[l].t;
				l++;
			}else{
				ans+=a[l].t;
				l++;
				r--;
			}
		}else{
			if(a[l].t>a[r].t){
				a[l].t-=a[r].t;
				r--;
			}else if(a[l].t<a[r].t){
				a[r].t-=a[l].t;
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

