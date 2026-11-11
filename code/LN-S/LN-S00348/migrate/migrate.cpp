#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,g,b,sum,cd[500005],u;
bool boo=true;
int main(){
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		int a=1;
		d*=2;
		for(int j=1;j<=n;j++){
			
			cin>>g;
			if(j>1&&boo==false){
				if(g-b==1){
					sum++;
					
				}else{
					a=1;
					boo=true;
					
				}
				
			}
			else if(j>1&&boo==true){
				if(g-b==1){
					a++;
				}else{
					a=1;
				}
				if(a==d){
					sum++;
					boo=false;
					
				}
			}
			
			b=g;
			
		}cd[u++]=sum;
		sum=0;
		boo=true;
	}
	for(int i=0;i<u;i++){
		cout<<cd[i]<<endl;
	}
	return 0;
}
