#include<bits/stdc++.h>
using namespace std;
string c[200006];
long long a[200006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(r>(n/2+n%2)&&l<(n/2+n%2)){
		if(c[l]!=c[n]){
		    cnt++;
		    l++,r--;
        }else{
		    cnt+=0;
		    l++,r--;
    	}
	}
	cout<<cnt;
	return 0;
}
