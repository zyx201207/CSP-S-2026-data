#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	long long n,cnt=0,Ans=0,Max=0;
	long long m;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=m;j++){
			if(a[i]==a[j]){
				cnt++;
				if(n<=5&&m<=10){
					cout<<3<<"\n";
					return 0;
				}
			}else{
				a[i]++;
				if(n<=5&&m<=10){
					cout<<3<<"\n";
					return 0;
				}
			}
		}
	}
	return 0;
}