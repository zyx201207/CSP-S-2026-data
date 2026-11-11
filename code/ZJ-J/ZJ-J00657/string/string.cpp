#include<iostream>
#include<cmath>
#include<string>
using namespace std;
string s;
long long cnt;
int n,a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}int i=0,j=n-1;
	while(i<j){
		if(c[i]!=c[j])cnt+=min(a[i],a[j]);
		if(a[i]==a[j]){i++;j--;}
		else if(a[i]>a[j]){a[i]-=a[j];j--;}
		else{a[j]-=a[i];i++;}
	}printf("%lld\n",cnt);
	return 0;
}
