#include<bits/stdc++.h>
using namespace std;
long long n,k,s,m;
struct node{
	int c,x,y;
}a[20010];
string b[20010];
int check(int t){
	int l=1,r=n,mid;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid].x<=t&&a[mid].y>=t){
			return mid;
		}
		else if(a[mid].y<t) l=mid+1;
		else r=mid-1; 
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>b[i];
		a[i].x=m+1;
		m+=a[i].c;
		a[i].y=m;
	}
	k=m/2;
	for(int i=1;i<=k;i++){
		if(b[check(i)]!=b[check(m-i+1)]){
			s++;
		}
	}
	cout<<s;
	return 0; 
}
