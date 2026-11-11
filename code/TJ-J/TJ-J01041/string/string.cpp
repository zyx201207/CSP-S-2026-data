#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,cnt=0,x[10000005];
	string c[10000005];
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>x[i]>>c[i];
	}
	for(int i=1;i<=a;i++){
		if(c[i]!=c[-1-i]){
			cnt+=x[i];
		}
	}
	cout<<cnt;
	
	return 0;
}

