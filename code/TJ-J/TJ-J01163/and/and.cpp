#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a,b,c;
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		for(int i=1;i<=m;i++){
			a+=c;
		}
	}
	b=a;
	int sum=0;
	if(a.size()%2==0){
		for(int i=a.size()-1;i>a.size()/2;i--){
			int js=0;
			if(a[js]!=b[i]){
				sum++;
			}
			js++;
		}
	}else{
		for(int i=a.size()-1;i>a.size()/2;i--){
			int js=0;
			if(a[js]!=b[i]){
				sum++;
			}
			js++;
		}
	}
	cout<<sum;
return 0;
}
