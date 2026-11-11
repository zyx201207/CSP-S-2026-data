#include<bits/stdc++.h>
using namespace std;
long long z,s,ss[200005];
int main(){
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin>>z>>s;

	for(int i=1;i<=z;i++){
		cin>>ss[i];
	}
	for(int i=1;i<=z;i++){
		for(int i=1;i<=z;i++){
			if(ss[i]>ss[i-1]){
				int ys=ss[i-1];
				ss[i-1]=ss[i];
				ss[i]=ys;
			}
		}
	}
		cout<<ss[s-1];
	return 0;
}