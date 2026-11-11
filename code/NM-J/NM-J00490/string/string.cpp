#include <bits/stdc++.h>
using namespace std;
int a[100000010];
char c[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	bool b=true;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(c[i]!=c[j]){
				b=false;
			}
		}
	}
	if(b){
		cout<<0<<endl;
	}
	else{
		int ans=0,d=0;
		for(int i=1;i<=n;i++){
			d+=a[i];
		}
		if(d%2==1){
			d=d/2+1;
		}
		else{
			d=d/2;
		}
		for(int i=1;i<=d;i++){
			if(d-i<=0&&d+1>n){
				break;
			}
			if(c[d-i]!=c[d+i]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
