#include <iostream>
#include <algorithm>
using namespace std;
const int N=2e5+20;
int n,k;
int a[N],b[N];
unsigned long long ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	unsigned long long maxx=0;
	for(int i=1;i<=100;i++){
		ans=a[i];
		for(int j=i+1;j<=i+k-1;j++){
			ans=ans&a[j];
		} 
		if(ans>maxx) maxx=ans;
	}
	cout<<maxx;
	return 0;
}
