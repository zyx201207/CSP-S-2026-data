#include<bits/stdc++.h> 
using namespace std;
int n;
char b[200010],t=0;
bool f=true;
long long x=0,a[200010],cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(i>1){
			if(b[i]!=b[i-1]){
				f=false;
				if(t==0){
					t=i;
				}
			}
		}
	}
	if(f==true){
		cout<<0;
		return 0;
	}
	for(int i=t;i<=n;i++){
		x+=a[i];
	}
	if(x%2==1){
		cnt=x-1;
	}else if(x%2==0){
		cnt=x;
	}
	cout<<cnt;
	return 0;
}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
