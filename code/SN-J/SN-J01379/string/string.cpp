#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[1005],p;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	cin>>p;
	if(p==1){
		int min1=10000;
		for(int i = 1;i<=n;i++){
			if(a[i]<min1){
				min1=i;
			} 
		}
		if(min1!=10000)
			cout<<min1;
		else cout<<"No";
	}
	if(p==2 || p==6){
		int min2=10000;
		for(int i = 1;i<=n;i++){
			if(a[i]==a[i+1]-1 && a[i]<min2 && a[i]!=a[n]){
				min2=i;
			}
		}
		if(min2!=10000)
			cout<<min2;
		else
			cout<<"No";
	}
	if(p==3){
		int min3=10000;
		for(int i = 1;i<=n;i++){
			if(a[i]==a[i+1] && a[i]<min3 && a[i]!=a[n]){
				min3=i;
			}
		}
		if(min3!=10000)
			cout<<min3;
		else
			cout<<"No";
	}
	if(p==4){
		int min4=10000;
		for(int i = 1;i<=n;i++){
			if(a[i]==a[i+1]-2 && a[i]<min4 && a[i]!=a[n]){
				min4=i;
			}
		}
		if(min4!=10000)
			cout<<min4;
		else
			cout<<"No";
	}
	if(p==5){
		int min5=10000;
		for(int i = 1;i<=n;i++){
			if(a[i]==a[i+1]+2 && a[i]<min5 && a[i]!=a[n]){
				min5=i;
			}
		}
		if(min5!=10000)
			cout<<min5;
		else
			cout<<"No";
	}
	if(p==7){
		int min7=10000;
		for(int i = 1;i<=n;i++){
			if(a[i]==a[i+1]+1 && a[i]<min7 && a[i]!=a[n]){
				min7=i;
			}
		}
		if(min7!=10000)
			cout<<min7;
		else
			cout<<"No";
	}
	return 0;
}


 
