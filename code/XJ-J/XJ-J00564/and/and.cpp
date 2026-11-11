#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,m,a1,a2,a3,a4;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a1;
		cin>>a2;
		cin>>a3;
		cin>>a4;
		if(a1 and a2 < a1 and a3){
			if(a1 and a2 < a1 and a4){
				if(a1 and a3<a1 and a4){
					if(a1>a4){
						cout<<a1;
					}
					else{
						cout<<a4;
					}
				}
			}
		}
	}
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	return 0;
}
