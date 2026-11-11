#include<bits/stdc++.h>
using namespace std;
int main(){
	fopen("crystal.in","r");
	fopen("crystal.in","w");
	long long n,m,a[10000000001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m%2==0&&m<=9999||m<=-9999){
		cout<<m/2<<endl;
	}else if(m%2!=0&&m<=9999||m<=-9999){
		cout<<m/2+1<<endl;
	}else if(m>20000||m<-20000){
		cout<<m/4<<endl;
	}else{
		cout<<m/3<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
