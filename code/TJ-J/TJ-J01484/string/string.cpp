#include<bits/stdc++.h>
using namespace std;
struct f{
	long long l;
	char a;
}s[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,z=0,y=0,t,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].l>>s[i].a;
	}
	if(n%2==0) t=0;
	else t=1;
	for(int i=1;i<=n/2;i++){
	if(s[i].a!=s[n-i].a){
			if(s[i].l-z<=s[n-i].l-y){
				sum+=s[n-i].l;
				z=s[n-i].l-s[i].l;
			}else{
				sum+=s[i].l;
				y=s[i].l-s[n-i].l;
		}
	}
	else{
		if(s[i].l-z<=s[n-i].l-y){
				sum+=s[n-i].l-s[i].l;
				z=s[n-i].l-s[i].l;
		}
		else{
			sum+=s[i].l-s[n-i].l;
				y=s[i].l-s[n-i].l;
		}
	}
}
	cout<<sum;
	return 0;
} 
