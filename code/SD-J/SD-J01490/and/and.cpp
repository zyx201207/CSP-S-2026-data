#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,c,max=0;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c;
		if(c>max){
			max=c;
		}
	}
	cout<<max;
}
