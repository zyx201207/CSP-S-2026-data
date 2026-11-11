#include<bits/stdc++.h>
using namespace std;
long long m,n;
vector<long long>a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	int sss;
	for(int i=0;i<n;i++){
		cin>>sss;
		a.push_back(sss);
	}
	for(int i=1;i<n;i++){
		bool flag=0;
		int xxx=0;
		for(int j=0;j<n;j++){
			if(a[i]==i){
				flag=1;
				xxx=j;
			}
		}
		for(int i=n-1;i>=xxx;i--){
			a.pop_back();
		}
	}
	int r=0;
	while(a[r]!=0){
		cout<<a[r]<<" ";
		r++;
	}
	return 0;
}
