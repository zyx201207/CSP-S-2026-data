//’≈≤” 12÷– SN-J00704 
#include <bits/stdc++.h>
using namespace std;
string s{
	long long num;
	char c;
}a[200005];
int n;
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin >> a[i].num >> a[i].c;
	}	
	int l;
	for(int i=1;l=n;i=l;){
		if(a[i].num>a[l].num){
			if(a[i].c! =a[l].c) ans+=a[l].num;
			k--;
			a[i].num-=a[l].num;
		}else if(a[i].num<a[l].num){
			if(a[i].c!=a[l].c)	ans+=a[i].c;
			a[l].num-=a[i].num;
			i++;
		}else{
			if(a[i].c!=a[l].c) ans+=a[i].num;
			i++;l--;
		}
	}
	cout << ans;
	return 0;
}
