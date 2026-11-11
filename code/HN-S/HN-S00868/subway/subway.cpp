#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("subway.in","r","stdin");
	//freopen("subway.out","w","stdout");
	int n,m,b,c,a[100000],d;
	string o;
	cin>>n>>m>>b>>c>>d;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		getline(cin,o);
	}
	int x,y;
	for(int i=1;i<=d;i++){
		cin>>x>>y;
		int sum=0;
		for(int j=x;j<=y;j++){
			sum+=a[j];
		}
		cout<<sum*2<<endl;
	}
	//cout<<"37"<<endl;
	//cout<<"12";
	return 0;
}
