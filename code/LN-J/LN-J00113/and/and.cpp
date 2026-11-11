#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long s=-1;
long long h[N];
long long n;
long long m;
bool cmp(long long a,long long b){
	return a>b;
}
void and(int c,int d,int e){
	if(c==n+1){
		if(d==m){
			if(e>=s){
				 s=e;
			}
		}
		return;
	}
	and(c+1,d+1,(e&h[c]));
	and(c+1,d,e)
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a,b,c;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	cin>>a>>b>>c;
	sort(a+1,a+1+n,cmp)
	cout<<s<<endl;;
	return 0;
}
