#include<bits/stdc++.h>
using namespace std;
struct node{
	long long f;
	char s;
}a[200005];
long long n;
int main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].f>>a[i].s;
	}
	long long ans=0;
	long long l=1,r=n;
	while(l<r){
		if(a[l].s!=a[r].s){
			if(a[l].f>=a[r].f){
				ans+=a[r].f;
				a[l].f-=a[r].f;
				r--;
			}
			else{
				ans+=a[l].f;
				a[r].f-=a[l].f;
				l++;
			}
		}
		else{
			if(a[l].f>=a[r].f){
				a[l].f-=a[r].f;
				r--;
			}
			else{
				a[r].f-=a[l].f;
				l++;
			}
		}
		if(a[l].f==0)l++;
		if(a[r].f==0)r--;
	}
	cout<<ans;
	return 0;
}