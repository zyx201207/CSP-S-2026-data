#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e3+5;
long long n,ans;
struct node{
	char s;
	long long num;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
	}
	long long l=1,r=n;
	while(l<r){
		long long z=min(a[l].num,a[r].num);
		if(a[l].s!=a[r].s){
			ans+=z;
		}
		if(a[l].num>a[r].num){
			a[l].num-=a[r].num;
			r--;
		}else if(a[r].num>a[l].num){
			a[r].num-=a[l].num;
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

