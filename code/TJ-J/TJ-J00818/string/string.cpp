#include<bits/stdc++.h>
using namespace std;
string b[200005]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long cnt=0,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			b[j+cnt]=c;
		}
		cnt+=a;
	}
	if(cnt%2!=0){
		for(int i=1;i<=cnt/2+1;i++){
			if(b[cnt/2+1-i]!=b[cnt/2+1+i]) sum++;
		}
	}else{
		for(int i=1;i<=cnt/2+1;i++){
			if(b[cnt/2+1-i]!=b[cnt/2+i]) sum++;
		}		
	}cout<<sum;
	return 0;
} 
