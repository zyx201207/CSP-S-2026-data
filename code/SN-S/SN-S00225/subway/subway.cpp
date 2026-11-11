#include<bits/stdc++.h>
using namespace std;
int w[5000005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,n,sum=0;
	cin>>a>>b>>c>>d>>n;
	for(int i=0;i<c;i++){
		cin>>w[i];
		sum+=w[i];
	}
	int wz,cnt=0;
	while(cin>>wz){
		cnt++;
	}
	for(int i=0;i<n;i++){
		cout<<sum<<endl;
	}
	
	return 0;
}
