#include<bits/stdc++.h>
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
const int N=2e5+5;
struct node{
	long long m;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	CLOSE
	int n,f=1;
	string s;
	cin>>n;
	long long l=1,r=n;
	cin>>a[1].m>>a[1].c;
	for(int i=2;i<=n;i++){
		cin>>a[i].m>>a[i].c;
		if(a[i].c!=a[i-1].c) f=0;
	}
	if(f==1){
		cout<<0;
		return 0; 
	}
    long long ans=0;
	while(l<r){
		if(a[l].m==a[r].m && a[l].c!=a[r].c){
			ans+=a[l].m;
		}
		else if(a[l].m!=a[r].m && a[l].c==a[r].c){
			ans+=abs(a[l].m-a[r].m);
		}
		else if(a[l].m!=a[r].m && a[l].c!=a[r].c){
			int t;
			t=abs(a[l].m-a[r].m);
			ans+=(min(a[l].m,a[r].m)+t);
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
}
