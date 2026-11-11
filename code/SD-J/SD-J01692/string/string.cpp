#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+5;
ll n,ans,s,t,tmp,awa,flag;
string a;
char c;
struct f{
	int q;
	char w;
}arr[N];
char check(int x){
	tmp = 0;
	for(int i = 1;i <= n;i++){
		tmp += arr[i].q;
		if(x > tmp) continue;
		else return arr[i].w;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		cin >> t >> c;s += t;
		arr[i].q = t,arr[i].w = c;
		if(i == 1){ awa = c,flag = 1;}
		else if(c != awa){ flag = 0; }
	}
	if(flag || n == 1){
		printf("0\n");
		return 0;
	}
	for(ll i = 0;i < s/2;i++){
		if(check(i) != check(s+1-i)){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
