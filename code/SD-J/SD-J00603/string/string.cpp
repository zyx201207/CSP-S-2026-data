#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e8+5;
char a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int cnt=1;
    for(int i=1;i<=n;i++){
    	int k;
    	char c;
    	cin>>k>>c;
    	a[cnt]=c;
    	cnt+=k;
	}
	for(int i=1;i<=cnt-1;i++){
		if((a[i]>='a'&&a[i]<='z')){
			a[i]=a[i];
		}
		else{
			a[i]=a[i-1];
		}
	}
	int ans=0;
	int y=cnt-1;
	for(int i=1;i<=(cnt-1)/2;i++){
		if(a[i]!=a[y]){
			ans++;
			y--;
		}
	}
	cout<<ans;
	return 0;
}
