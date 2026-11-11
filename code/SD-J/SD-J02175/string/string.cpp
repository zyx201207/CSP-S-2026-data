#include<bits/stdc++.h>
using namespace std;
const long long N=100000+6;
long long n,cnt,an=1;
long long a[N];
char b[N];
string L,x,y;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","w","stdout");
	scanf("%d",&n);
	long long an=0;
	for(long long i=1;i<=n;++i){
	scanf("%d%s",&a[i],&b[i]);
	}
	for(int i=1;i<=n;++i){
		/*°ÑLÐ´³öÀ´*/ 
		for(int j=a[i-1]+1;j<=a[i-1]+a[i];++j){
			L[j]=b[i];
		} 
	} 
	int l=1,R=sizeof(L),ou=0;
	while(l!=R){
		if(L[l]!=L[R]){
			cnt++;
		}
		l++;R--;
		ou+=2;
	}
	printf("%d\n",cnt);
	return 0;
}
