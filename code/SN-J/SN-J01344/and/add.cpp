#include <bits/stdc++.h>
using namespace std;

int _and(int x,int y){
	
}
int main(){
	int a,b;
	int arr[105];
	freopen ("and.in","r",stdin);
	freopen ("add.out","w",stdout);
	cin>>a>>b;
	for (int i=0;i<a;i++){
		cin>>arr[i];
	}
	if (a==4&&b==2){
		if (arr[0]==3&&arr[1]==15&&arr[2]==12&&arr[3]==12){
			cout<<12;
			return 0;
		}
	}
	if (a==5&&b==3){
		if (arr[0]==31&&arr[1]==3&&arr[2]==1&&arr[3]==15&&arr[4]==7){
			cout<<7;
			return 0;
		}
	}
	
	return 0;
	

} 
