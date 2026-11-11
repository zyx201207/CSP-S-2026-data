#include<bits/stdc++.h>
using namespace std;
long long a[100010],b[100010];
long long n,m,o;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n); 
	for(int i=2;i<=n;i++){
		int e=0,y=m;
		for(int j=i;j>=1;j--){
			if(a[j]+y>=a[i]){
				e++;
				y-=a[i]-a[j];
			}
			if(y<=0)break;
		}
		if(e>o)o=e;
	}
	cout<<o<<"\n";
}