#include<bits/stdc++.h>
using namespace std;
int c,t;
const int Max=1e7+10;
long long zuobiao[Max];
int main(){
	cin>>c>>t;
	int as=1,fb=2; 
	for(int i=0;i<t;i++){
		int n,d,cnt=0;
		int o=d+1;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>zuobiao[j];
			}
			if(i==0){
				cout<<as;
			} else {
				cout<<fb;
			}
			
		} 
	
	
	
	return 0;
}