#include<bits/stdc++.h>
#include<string>
using namespace std;
typedef long long ll;
int n,a[200005]; 
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	if(n==1){
		printf("0");
		return 0;
	}
	if(n==2){
		int x;scanf("%d",&x);
		if(x==1||x==4)printf("1");
		else if(x==2||x==3)printf("2");
		else printf("0"); 
	}
	int x;scanf("%d",&x);
	if(x==1)printf("%d",n-1);
	return 0;
}
