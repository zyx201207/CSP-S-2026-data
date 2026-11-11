#include<bits/stdc++.h>
using namespace std;
long long n,m,A,B;
long long a[500005],b[500005];
long long ans;
int min1=2147283647;
bool o=1;
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==i)
			A++;
	}
//	for(int i=2;i<=n;i++){
//		cout<<b[i]<<" ";
//	}
	for(int i=3;i<=n;i++){
		if(b[i]==b[i-1])
			B++;
	}
	if(A==n){
		int g=0,c=0;
		while(m-c*g>=0&&g<n){
			c=b[3];
			m-=c*g;
			g++;
		}
		ans=g;
		o=0;
	}
	else if(B==n-2){
		int g=0,c=0;
		while(m-c*g>=0&&g<n){
			c=b[3];
			m-=c*g;
			g++;
		}
		ans=g;
		o=0;
	}
	else if(n<=16&&o){
		int hm[17]={1},h=0;
		for(int i=1;i<=n;i++){
			int p=m;
			h+=b[hm[i]+i];
			while(m-h>=0&&hm[i]+i<n){
				h+=b[hm[i]+i];
				m-=h;
				hm[i]++;
	//			cout<<h<<" ";
			}
			m=p;	
			h=0;
	//		cout<<endl;
		}
		int c=-1;
		for(int i=1;i<=n;i++){
	//		cout<<hm[i]<<" ";
			c=max(hm[i],c);
		}
		ans=c;
	}
	cout<<ans;
	return 0;
} 
