#include<bits/stdc++.h>
using namespace std;

long long x[2000000+10];
long long cha[2000000+10];
int zui[2000000+10];
bool flog=1;
bool chaz(int z,int y){
	if(cha[z]!=cha[z+1])flog=0;
	if(zui[z]==y&&flog==0){
		return 1;
	}else{
		chaz(zui[z],y);
	}
}

int main()
{
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d){
					zui[i]=j-1;
					break;
				}
				cha[i]=x[j]-x[i];
			}
		}
		int num=0;
		cout<<num;
	}

	return 0;
}
