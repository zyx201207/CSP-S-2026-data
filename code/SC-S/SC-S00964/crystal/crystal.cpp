// 1.crystal
// N
#include<bits/stdc++.h>
using namespace std;
void read(int &n){
	n=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		n=n*10+int(ch-'0');
		ch=getchar();
	}
}

int n,m;
vector<int> a,b;

int jin(const int &p){
	int mnj=INT_MAX;
	for(int i=1;i<=n;i++){
		if(i==p) continue;
		if(abs(a[i]-a[p])<mnj) mnj=i;
	}
	return mnj;
}

int ff(const int &m, const int &p){
	if(abs(p-b[p])>m) return 1;
	int t=b[p], mx=INT_MIN;
	for(int i=1;i<=n-1;i++){
		mx=max(mx,ff(m-abs(p-t),t));
		t=b[t];
	}
	return mx;
}

bool chk(const int &x){return x*x-x==n*n+n-m*2;}

int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	a.resize(n+2);b.resize(n+2);
	bool A=1,B=1; int cha;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i) A=0;
		if(i==2) cha=abs(a[1]-a[2]);
		else if(i>=3){
			if(abs(a[i]-a[i-1])!=cha) B=0;
		}
	}
    // CE ?
	if(A){
		//puts("(debug[A])");
		int x=sqrt(n*n-m*2);
		printf("%d\n",n-x+1);
		return 0;
	}
	if(B){
		// 1 3 5 7 9 11
		// 2 4 6 8 10
		// 1 4 7 10 13 16
		//puts("(debug[B])");
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r)/2;
			if(chk(mid)) l=mid;
			else r=mid;
		}
		printf("%d\n",n-mid+1);
		return 0;
	}
	//--------
	for(int i=1;i<=n;i++) b[i]=jin(i);
	int mx=INT_MIN;
	for(int i=1;i<=n;i++) mx=max(mx,ff(m,i));
	printf("%d\n",mx);
	return 0;
}
/*
n=9, m=4;
a={3,3,3,2553,2554,2555,2555,2556,2557};
b={2,1,1,   5,   4,   5,   6,   6,   8};
*/
