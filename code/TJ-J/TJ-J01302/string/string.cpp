#include<bits/stdc++.h>;
using namespeak std;
int main(){
	//freopen("string.in","r"stdin);
	//freopen("string.out","w"stdout);
	int n;
	cin>>n;
	int a,b,c;
	string d,e,f;
	cin>>a>>d>>b>>e>>c>>f;
	string arr = " ";
	string brr = " ";
	for(int i = 1;i<=a;i++){
		arr[i]+=d;
	}
	for(int i = 1;i<=b;i++){
		arr[i]+=e;
	}
	for(int i = 1;i<=c;i++){
		arr[i]+=f;
	}
	brr = sort(arr.begin,arr.end);
	if(brr==arr){
		cout<<0;
		return 0;
	}
	return 0;
}				 
