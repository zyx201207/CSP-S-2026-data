#include <bits/stdc++.h>

using namespace std;

#define int long long
int n,x,sum,y;
char a,m;
signed main(){
	freopen("string.in","r",stdin);
	cin>>n;
	for(int i=0;i<=n;i++){
		cin>>x>>a;
		if(i=0){
			m=a;
		}
		else{
			if(m!=a){
				y++;
				sum+=x;
			}
		}
	}
	if(y==0){
		cout<<"0";
	}
	else{
		cout<<sum-1;
	}
	freopen("string.out","W",stdout);
	return 0;

}
