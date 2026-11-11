#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int a,b,c,d,e,sum=0;
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=c;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=c+2;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	for(int i=1;i<=c+2;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=e;i++){
		int n,m;
		for(int j=1;j<=1;j++)cin>>n>>m;
	}
	cout<<sum<<endl;
	cout<<sum;
	return 0;
}//这个骂的更脏，哈哈哈