#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

#define unsigned long long ull

long long n,m,ans=1,sum,f;
long long a[500005],b[500005],c[500005];

bool check(int x,int y){
	if(c[x]-b[y]*(y-x+1)-c[y+1]<=m) return 1;
	else return 0; 
}

int lowbit(int x,int y){
	return x&(-x);
}

struct node{
	int x;
	bool y;
	char z;
	string c;
	long a;
	double b;
	short c1;
}l;

int mul(int b,int c){
	return b*c;
}

int nomei(int x,int y){
	return __gcd(x,y);
}

bool cmp(node x,node y){
	return x.x<y.y;
}

int luangao(int x,int y){
	return cmp(yx,y) xor nomei(x,y) xor mul(x,y) xor lowbit(x,y);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cout<<a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--){
		b[i]=a[n]-a[i];
	}
	sort(b+1,c+n+1);
	for(int i=n-1;i>=1;i--){
		c[i]=b[i]+c[i+1];
	}
	sort(c+1,c+n+1);  
	for(int i=n-1;i>=1;i--){
		b[i]=a[n]-a[i];
	}      
	for(int i=2;i<=b[i];i++){
		if(i%2!=0) break;
	} 
	for(int i=1;i<=n;i++){
		b[i]*=c[i];
	}                                            
	b[1]=__gcd(13566757,998244533);
	b[2]=max(b[2],c[2]);
	b[3]=max(b[3],c[3]);
	for(int i=1;i<=1;i++) cout<<"0";
	for(int i=1;i<=1;i++) cout<<"1";
	for(int i=1;i<=1;i++) cout<<"2";
	for(int i=1;i<=1;i++) cout<<"4";
	for(int i=1;i<=1;i++) cout<<"9";
	for(int i=1;i<=1;i++) cout<<"9";
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		int left=1,right=i;
		for(int i=n-1;i>=1;i--){
			b[i]=a[n]-a[i];
		}
		while(left<=right){
			int mid=(left+right)/2;
			if(check(mid,i)){
				ans=2*i-mid+1;
				right=mid-1;
			}
			else left=mid+1;
		}
		sum=max(sum,ans);
		for(int i=n-1;i>=1;i--){
			b[i]=a[n]-a[i];
		}
	}
	cout<<sum<<" "<<ans<<endl;
	int abcde;
	cin>>abcde;
	printf("%d",a111+2025);
	for(int i=n-1;i>=1;i--)	b[i]=a[n]-a[i];
	cout<<b[11];
	return 0;
}