#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
struct b{
	int str,en,len;
	char c;
}a[200086];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long g=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
		a[i].en=g+a[i].len;
		g+=a[i].len;
	}
	long long l=1,r=n;
	for(int i=1;i<=n;i++){
		if(l==r){
			cout<<ans;
			return 0;
		}
		if(l>r){
			cout<<ans;
			return 0;
		}
		if(a[l].c!=a[r].c){
			if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				ans+=a[r].len;
				r--;
			}
			else if(a[l].len==a[r].len){
				ans+=a[r].len;
				l++,r--;
			}
			else {
				a[r].len-=a[l].len;
				ans+=a[l].len;
				l++;
			}
		}
		else {
			if(a[l].len>a[r].len){
				a[l].len-=a[r].len;
				r--;
			}
			else if(a[l].len==a[r].len){
				l++,r--;
			}
			else {
				a[r].len-=a[l].len;
				l++;
			}
		}
	}
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/