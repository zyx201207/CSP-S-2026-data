#include<bits/stdc++.h>
using namespace std;
struct C{
	int a;
	char c;
} a[200010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;++i){
		int ai;
		char c;
		cin>>ai>>c;
		a[i]={ai,c};
	}
	long long ans=0;
	for(int i=0,j=n-1;i<j;){
		if(a[i].a==a[j].a){
			if(a[i].c!=a[j].c)ans+=a[i].a;
			++i;--j;
		}
		else if(a[i].a>a[j].a){
			if(a[i].c!=a[j].c)ans+=a[j].a;
			a[i].a-=a[j].a;
			--j;
		}
		else if(a[i].a<a[j].a){
			if(a[i].c!=a[j].c)ans+=a[i].a;
			a[j].a-=a[i].a;
			++i;
		}
	}
	cout<<ans;
	return 0;
}