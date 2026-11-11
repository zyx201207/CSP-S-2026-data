#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],num=0,ct=0,b[N];
int n,m;
bool g[N]={0};
long long q(long long h,long long k){
	long long sum=0;
	if(h==0) return k;
	long long op=1;
	while(h>0&&k>0){
		if(h%2==1&&k%2==1){
			sum+=op;
		}
		h/=2;
		k/=2;
		op*=2;
	}
	return sum;
}
void f(int pos){
	if(pos==m+1){
		ct=b[1];
		for(int i=2;i<=m;i++){
			ct=q(ct,b[i]);
		}
		num=max(ct,num);
		
	}
	for(int i=1;i<=n;i++){
		if(!g[i]&&a[i]>=b[pos-1]){
			g[i]=1;
			b[pos]=a[i];
			f(pos+1);
			g[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[0]=0;
	f(1);
	cout<<num;
	return 0;
}
