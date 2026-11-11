#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n,l,r,ans;
struct node{
	long long m;
	char x;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].x;
	}
	l=1,r=n;
	while(l<r){
		if(a[l].x==a[r].x){
			a[l].m-=min(a[l].m,a[r].m);
			a[r].m-=min(a[l].m,a[r].m);
		}
		else{
			ans+=min(a[l].m,a[r].m); 
			a[l].m-=min(a[l].m,a[r].m);
			a[r].m-=min(a[l].m,a[r].m);
		}
		if(a[l].m==0){
			l++;
		}
		if(a[r].m==0){
			r--;
		}
	}
	cout<<ans;
	return 0;
}


