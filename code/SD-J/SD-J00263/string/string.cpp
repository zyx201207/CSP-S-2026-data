#include<bits/stdc++.h>
using namespace std;
char a[1000000005];
long long x,s=0,sum=0;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		cin>>x>>c;
		for(int i=s+1;i<=s+x;i++)a[i]=c;
		s+=x;
	}
	for(int i=1;i<=s/2;i++){
		if(a[i]!=a[s-i+1])sum++;
	}
	cout<<sum;
	return 0;
}
