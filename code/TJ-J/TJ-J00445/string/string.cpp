#include<bits/stdc++.h>
using namespace std; 
int s[1000001],a[1001],b[1001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	
	int sum=1;
	while(n--){
		int x,yy;
		string y;
		cin>>x>>y;
		yy=y[0]-'0';
		for(int i=sum;i<=sum+x;i++){
			s[i]=yy;
		}
		sum+=x;
	}
	sum--;
	int num=0;
		for(int i=1;i<=sum/2;i++){
			a[i]=s[i];
			b[i]=s[i+sum/2+sum%2];
		}
	for(int i=1;i<=sum/2;i++){
		if(a[i]!=b[i])num++; 
		}
		cout<<num;

	
	return 0;
}
