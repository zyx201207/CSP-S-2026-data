#include<iostream>
#define ll long long
using namespace std;
int n;
ll ans,len;
int posl,posr;
struct node{
	int sz;
	char c;
}a[200005];
void fun(int &posl,int &posr){
	int minlen,pos,flag = 0;
	if(a[posl].c != a[posr].c)flag = 1;
	if(a[posl].sz > a[posr].sz){
		minlen = a[posr].sz;
		if(flag)ans += a[posr].sz;
		a[posl].sz -= a[posr].sz;
		pos = posr;
		posr--;
	}
	else if(a[posl].sz < a[posr].sz){
		minlen = a[posl].sz;
		if(flag)ans += a[posl].sz;
		a[posr].sz -= a[posl].sz;
		pos = posl;
		posl++;
	}
	else{
		if(flag)ans += a[posl].sz;
		posl++;
		posr--;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i].sz>>a[i].c;
		len += a[i].sz;
	}
	posl = 1,posr = n;
	while(posl < posr){
		fun(posl,posr);
	}
	cout<<ans;
	return 0;
}
