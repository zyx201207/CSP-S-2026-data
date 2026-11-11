#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x[n];
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	int s;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(x[i]==x[j]&&i!=j){
				s=x[i];
			}
		}
	}
	cout<<s<<endl;
	return 0; 
}
