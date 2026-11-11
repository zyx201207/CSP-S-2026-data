#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char ch;
}a1[200005],a2[200005];
long long s1[200005],s2[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i].a>>a1[i].ch;
		s1[i]=s1[i-1]+a1[i].a;
	}
	for(int i=1;i<=n;i++){
		a2[i]=a1[n+1-i];
		s2[i]=s2[i-1]+a2[i].a;
	}
	long long p1=1,p2=1,cnt=0;
	for(long long i=1;i<=s1[n]/2;i++){
		p1+=(i>s1[p1]);
		p2+=(i>s1[p2]);
		if(a1[p1].ch!=a2[p2].ch)cnt++;
	}
	cout<<cnt;
    return 0;
}
/*
 MSL
 / \
 \ /
 1.00km
*/
