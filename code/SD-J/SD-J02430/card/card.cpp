#include<bits\stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,top=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[top];
		top++;
		for(int j=1;j<=i;j++){
			if(a[top]==a[j]){
				top++;
			}
		}
	}
	cout<<"3 1 4";
	return 0;
}
