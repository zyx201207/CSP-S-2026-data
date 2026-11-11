#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct jg{
	long long g;
	char id;
}a[N];
long long n,ans,l,m,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].g>>a[i].id,l+=a[i].g;
	while(s<=l/2){
		m++;
		s+=a[m].g;
	}
//	cout<<m<<endl;
	int i=1,j=n;
	while(i<=m&&j>=m){
		if(a[i].g==0)i++;
		if(a[j].g==0)j--;
		if(a[i].id!=a[j].id){
			if(a[i].g>=a[j].g){
				ans+=a[j].g;
				a[i].g-=a[j].g;
				a[j].g=0;
			}
			else {
				ans+=a[i].g;
				a[j].g-=a[i].g;
				a[i].g=0;
			}
		}
		else {
			if(a[i].g>a[j].g)a[i].g-=a[j].g,a[j].g=0;
			if(a[i].g<a[j].g)a[j].g-=a[i].g,a[i].g=0;
			if(a[i].g==a[j].g)a[i].g=a[j].g=0;
		}
//		cout<<endl<<a[i].g<<" "<<a[i].id<<endl;
//		cout<<a[j].g<<" "<<a[j].id<<endl;
//		cout<<i<<" "<<j<<endl;
//		cout<<ans<<endl;
	}
	cout<<ans;
	return 0;
}