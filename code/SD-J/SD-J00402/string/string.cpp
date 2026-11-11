#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct Node{
	long long a;
	char b;
}a[200005];
long long step;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
    int l=1,r=n;
    while(l<r){
    	step+=abs(a[l].a-a[r].a);
    	a[r-1].a+=a[l].a-a[r].a;
    	a[r].a=a[l].a,a[r].b=a[l].b;
    	l++,r--;
	} 
	cout<<step;
	return 0;
}
