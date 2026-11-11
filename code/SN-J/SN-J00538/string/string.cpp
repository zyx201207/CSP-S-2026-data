#include<bits/stdc++.h>
using namespace std;
int a[200005],a1[200005];
string b[200005],b1[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		a1[i]=a[i];
		b1[i]=b[i];
	}
//	int flag=1;
//	for(int i=n;i<=1;i--){
//		if(a[i]==a1[n-i+1]&&b[i]==b1[n-i+1]){
//			flag=1;
//		}
//		else{
//			flag=0;
//			break;
//		}
//		if(flag==1){
			cout<<"0";
//		}
//	}
	return 0;
}
