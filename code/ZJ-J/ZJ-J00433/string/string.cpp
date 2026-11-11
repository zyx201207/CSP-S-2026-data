#include<bits/stdc++.h>
using namespace std;
long long n;
struct k{
	int x;
	char z;
} a[2000001];
int ans,l=0,d=0;
char s[1000001],t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int f=1;
    for(int i=1;i<=n;i++) {
	cin>>a[i].x>>a[i].z;
	if(a[i].z!=a[i-1].z&&i!=1) f=0;
	}
	if(f==1){
	cout<<0;
	return 0;
	}
    for(int j=1;j<=n;j++){
    	l+=a[j].x;
    	for(int i=d;i<=d+a[j].x;i++){
    		s[i]=a[j].z;
		}
		d=a[j].x;
	}
	for(int i=0;i<l/2+1;i++){
		if(s[i]!=s[l-i]){
		    ans++;
		} 
	}
	cout<<ans;
	return 0;
}
