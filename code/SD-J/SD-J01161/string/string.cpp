#include<bits/stdc++.h>
using namespace std;
long long n=0,L=0,ans=0;
struct shu{
	long long y;
	string s;
}a[200005];
string S;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1 ; i<=n ; i++) cin>>a[i].y>>a[i].s;
	int l=1,r=n;
	while(l<r){
		if(a[l].s!=a[r].s) ans+=min(a[l].y,a[r].y);
		if(a[l].y>a[r].y){
				a[l].y-=a[r].y;
				r--;
			}else if(a[l].y<a[r].y){
				a[r].y-=a[l].y;
				l++;
			}else{
				l++;
				r--;
			}
	}
	cout<<ans;
	return 0;
} 
