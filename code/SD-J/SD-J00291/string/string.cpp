#include<bits/stdc++.h>
using namespace std;
long long n,a,sum=0,ans=0;
string c,S;
int main(){ 
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		for(int j=1;j<=a;j++){
			S+=c;
		}
	}
	int f=(sum-1)/2,t=sum/2;
	for(int i=t;i<sum;i++){
		int p=i-f;
		if(S[t-p]!=S[i]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
