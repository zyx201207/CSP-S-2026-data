#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r,sum;
struct s{
	long long x;
	char c;
}a[200005];
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	while(l<=r){
		if(a[l].x>a[r].x){
			if(a[l].c!=a[r].c)	sum+=a[r].x;
			a[l].x-=a[r].x;
			r--;
		}
		else{
			if(a[l].c!=a[r].c)	sum+=a[l].x;
			a[r].x-=a[l].x;
			l++;
		}
	}
	cout<<sum;
	return 0;
}
