#include<bits/stdc++.h>
using namespace std;
int n;
struct A{
	unsigned long long a;
	unsigned long long s;
	char c;
}abc[200010];
char sear(int x){
	for(int i=1;i<=n;i++){
		if(abc[i].s>=x){
			return abc[i].c;
			break;
		}
	}
}
int hui(int l){
	unsigned long long ans=0;
	for(int i=1;i<=(l+1)/2;i++){
		if(sear(i)!=sear(l-i+1)) ans++;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	abc[0].s=0;
	int l=0;
	for(int i=1;i<=n;i++){
		cin>>abc[i].a>>abc[i].c;
		abc[i].s=abc[i-1].s+abc[i].a;
		l+=abc[i].a;
	}
	cout<<hui(l);
	return 0;
}

