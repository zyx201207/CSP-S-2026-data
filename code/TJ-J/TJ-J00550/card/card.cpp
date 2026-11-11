#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	long long a[100000]={};
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	int s1=0;
	if(n-m>a[1]){
		s1=n;
	}
	else{
		s1=m;
	}
	int s2=0;
	if(n-m<=a[1]){
		s2=n;
	}
	else{
		s2=m;
	}
	cout<<s1<<" "<<a[1]<<" "<<s2;

return 0;
fclose(stdin);
fclose(stdout);
}

