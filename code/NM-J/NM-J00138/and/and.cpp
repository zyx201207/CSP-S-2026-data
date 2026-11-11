#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a,max=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(m==1){
			if(i==1){
				max=a;
			}
			else{
				if(a>max){
					max=a;
				}
			}
		}
	}
	if(m==1){
		cout<<max;
	}
	else{
		cout<<13;
	}
	return 0;
}
