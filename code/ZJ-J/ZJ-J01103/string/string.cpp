#include<bits/stdc++.h>
using namespace std;
struct{
	int shu;
	char zi;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].shu>>a[i].zi;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		if(a[1].zi==a[2].zi){
			cout<<"0";
			return 0;
		}
		else{
			cout<<min(a[1].shu,a[2].shu);
			return 0;
		}
	}
	return 0;
} 
