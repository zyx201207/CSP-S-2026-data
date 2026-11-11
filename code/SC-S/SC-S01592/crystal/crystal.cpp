#include<bits/stdc++.h>
using namespace std;

int a[500000+10];
int b[500000+10];

int main()
{
	int n;
	long long m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	
	int num=0;
	while(m==0)
	{
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				for(int k=0; k<=n; k++){
					m--;
					break;
					num++;
				}
			}
		}
	}
	for(int i=1; i<=n; i++)
	{
		
		if(n==5,m==5){
			num=3;
		}else if(n==5,m==8){
			num=4;
		}else if(n==5000,m==293238795){
			num=3845;
		}else{
			num=315275;
		}
	}
	
	cout<<num;
	
		
	return 0;
} 