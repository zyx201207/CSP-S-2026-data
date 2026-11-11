#include<cstdio>
#include<iostream>
using namespace std;
int c[500005];
int main(){
	freopen(" crystal.in","r",stdin);
	freopen(" crystal.ans","w",stdout);
	long long a,b;
	int max=0;
	int x=0;
	int s=0;
	
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a;i++){
		
		for(int j=0;j<a;j++){
			
			if(s+(c[i]-c[j])<=b){
				
				if(c[i]>=c[j]){
					s=s+(c[i]-c[j]);
					x++;
					
				}
			}
			else{
				break;
			}
		}
		
		if(x>max){
			max=x;
		}
		x=0;
		s=0;
	}

	cout<<max;
} 
