#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],maxx,sum,f,t[N];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++){
		sum=sum+a[i];
		t[i]=sum+m;
	}
	for(int i=1;i<=n;i++){
		f=i*a[i];
		if(t[i]/a[i]==i){
			maxx=i;
		}
	}
	printf("%d",maxx);
}
