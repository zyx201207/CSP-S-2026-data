#include<bits/stdc++.h>
using namespace std;
const int N=2*10000+10;
string s;
long long n,a[N],cnt,sum;
char c[N];
bool flag=true;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
	}
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]){
			flag=false;
			break;
	    }
	}
	if(flag){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			sum+=1;
			s[sum]=c[i];
		}
	}
	for(int i=1;i<=sum/2;i++){
		if(s[i]!=s[sum-i+1]){
			cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
} 
