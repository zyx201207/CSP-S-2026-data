#include<bits/stdc++.h>
using namespace std;
struct ii{
	int a;
	char b;
}a[200010];
int b[20],l=1;
void w(int n){
	b[0]+=n;
	int m=0;
	for(int i=0;i<l;i++){
		if(b[i]/10&&i+1==l)l++;
		b[i+1]+=b[i]/10;
		b[i]%=10;
	}//cout<<n<<"#";
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x,y;cin>>n;int j=n-1;
	for(int i=0;i<n;i++)
		cin>>a[i].a>>a[i].b;
	for(int i=0;;){
		if(a[i].b!=a[j].b)w(min(a[i].a,a[j].a));
		a[i].a-=min(a[i].a,a[j].a);
		a[j].a-=min(a[i].a,a[j].a);
		if(a[i].a==0)i++;
		if(a[j].a==0)j--;
		if(j==i){
			break;
		}
		//cout<<i<<' '<<a[i].a<<' '<<a[i].b<<"!"<<j<<' '<<a[j].a<<' '<<a[j].b<<endl;
	}for(int i=l-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
