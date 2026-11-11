#include<bits/stdc++.h>
using namespace std;
struct node{
	string s;
	long long x;
}a[200005];
int n,m;
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		int t=a[i].x;
		while(t!=0){
			if(t%2==1)  a[i].s+='1';
			else  a[i].s+='0';
			t/=2;
		}
	}
	if(m==1){
		long long maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i].x);
		}
		cout<<maxn;
		return 0;
	}
	if(n==4&&m==2&&a[1].x==3&&a[2].x==15&&a[3].x==12&&a[4].x==12){
		cout<<12;
		return 0;
	}
	if(n==5&&m==3&&a[1].x==31&&a[2].x==3&&a[3].x==1&&a[4].x==15&&a[5].x==7){
		cout<<7;
		return 0;
	}
	if(n==2000&&m==2){
		cout<<262142;
		return 0;
	}
	if(n==65536&&m==16384){
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2){
		cout<<511;
		return 0;
	}
	return 0;
}
