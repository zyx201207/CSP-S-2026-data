#include<bits/stdc++.h> 
using namespace std;

int cmp(int a,int b){
	if(b!=3 && a!=3)return a>b;
	else if(a==3)return b>0;
	else return a>0;
}
int if1(int a){
	int sum=0;
	while(a){
		sum+=a&1;
		a=(a>>1);
	}
}
long long m,n,b,a[20005];

bool p=1;
struct ad{
	int an;
	int nd;
};
ad a1[20010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a1[i].an=a[i];
		a1[i].nd=if1(a[i]);
		if(a[i]>4)p=0;
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}else if(p){
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)b=a[n-1] and a[n-2];
		cout<<b;
	}else if(m==2){
		sort(a,a+n);
		b=a[n-1] and a[n-2];
		cout<<b;
	}else if(m+1==n){
		sort(a,a+n);
		b=a[n-1];
		for(int i=n-2;i>0;i--)b=b & a[i];
		cout<<b;
	}
	return 0;
}
