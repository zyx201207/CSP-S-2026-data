#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long int ans;
struct node{
	int num;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	int l=1,r=n,lc=a[1].c,rc=a[n].c;
	while(l+1<=r){
		if(a[l].num>=a[r].num){
			a[l].num-=a[r].num;
			if(lc!=rc){
				ans+=a[r].num;
				r--;
				rc=a[r].c;
				continue;
			}
			else {
				r--;
				rc=a[r].c;
			}
		}
		else {
			a[r].num-=a[l].num;
			if(lc!=rc){
				ans+=a[l].num;
				l++;
				lc=a[l].c;
				continue;
			}
			else {
				l++;
				lc=a[l].c;
			}
		}
		if(a[r].num<=0){
				r--;
				rc=a[r].c;
			}
		if(a[l].num<=0){
				l++;
				lc=a[l].c;
		}
	}
	cout<<ans;
	return 0;
}