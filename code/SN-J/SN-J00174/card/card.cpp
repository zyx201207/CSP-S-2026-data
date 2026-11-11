//Ô­è÷Ðù 440514201308033019 SN-J00174
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int one=0,two=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[n]){
			if(a[n]==1){
				one++;
			}
			else{
				two++;
			}
		}
		else{
			one++,two++;
		}
	}
	cout<<one<<" "<<two;
} 
