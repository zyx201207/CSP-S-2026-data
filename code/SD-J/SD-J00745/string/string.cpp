#include<bits/stdc++.h>
using namespace std;
struct d {
	long long s;
	char c;
}a[400010];
long long n,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l].s>a[r].s){
			if(a[l].c!=a[r].c){
				ans+=a[r].s;
			}
			a[l].s-=a[r].s;
			r--;
		}else if(a[l].s<a[r].s){
			if(a[l].c!=a[r].c){
				ans+=a[l].s;
			}
			a[r].s-=a[l].s;
			l++;
		}else{
			if(a[l].c!=a[r].c){
				ans+=a[r].s;
			}
			r--;
			l++; 
		}
	}
	cout<<ans;
	
	
	
	return 0;
}
