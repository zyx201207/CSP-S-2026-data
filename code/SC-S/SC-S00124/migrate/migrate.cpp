#include <bits/stdc++.h>
using namespace std;
int n[100000000],d[100000000],x[100000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);		
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n[i]>>d[i];
		for(int j=0;j<d[i];j++){
			cin>>x[j];
		}
	}
	int sum=0;
	for(int i=0;i<t;i++){
		cin>>n[i]>>d[i];
		for(int j=0;j<d[i];j++){
			if(d[i]==x[j]){
				sum++;
			}
		}
	}
	cout <<sum;
	return 0;
}