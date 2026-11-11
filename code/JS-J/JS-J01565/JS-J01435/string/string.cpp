#include <bits/stdc++.h>
using namespace std;
int n,a[200010],ans,ll;
char c[200010];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin.ignore(1000,'\n');
		cin>>a[i];
		cin>>c[i];
		ll+=a[i];
	}
	int d=1,aaa=0,p=1,aa=0;
	for(int i=1;i<=ll/2;i++){
		if(i-aaa>=a[d]) {
			d++;
			aaa+=a[d-1];
		}
		
		if(c[d]!=c[ll+1-p]){
			ans++;
			aa++;
		}
		
		if(aa>=c[ll+1-p]){
			p++;
			aa=0;
		}

		i++;
	}
	cout<<ans;
	return 0;
}
