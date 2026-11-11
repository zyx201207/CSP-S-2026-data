#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,sum,ans;
struct node{
	int len;
	string s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].s;
		sum+=a[i].len;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].s!=a[r].s){
			if(a[l].len<a[r].len){
				ans+=a[l].len;
				a[r].len-=a[l].len;
				a[l].len=0;
				l++;
			}
			else if(a[l].len==a[r].len){
				ans+=a[l].len;
				a[l].len=0;
				a[r].len=0;
				l++,r--;
			}
			else if(a[l].len>a[r].len){
				ans+=a[r].len;
				a[l].len-=a[r].len;
				a[r].len=0;
				r--;
			}
		}
		else{
			if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				a[r].len=0;
				r--;
			}
			else if(a[l].len==a[r].len){
				a[l].len=0;
				a[r].len=0;
				l++,r--;
			}
			else{
				a[r].len-=a[l].len;
				a[l].len=0;
				l++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
