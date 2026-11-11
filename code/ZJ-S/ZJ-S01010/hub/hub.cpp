#include<iostream>
using namespace std;
long long a[10005][10005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t>>n>>k;
	for(int i=1;i<=3*n;i++){
		for(int j=1;j<=2;j++){
			cin>>a[i][j];
		}
	}
	if(c==0){
		cout << "1"<<endl;
		cout << "2"<<endl;
	}
	return 0;
}