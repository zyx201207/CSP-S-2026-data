#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){ 
		int max=0;
		if(m>max){
			max=m;
		}
		cout<<max;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
