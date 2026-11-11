#include<iostream>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
    int a[n];
    int b[n];
    int c[n];
    for(int i = 0;i < n;i++){
		cin>>a[i];
}
for(int p = 0;p < n;p++){
	for(int i = 0;i < n;i++){
	b[i] = a[i];
	for(int j = 0;j <= i;j++){
		if(b[j] == b[i]) i = j;
	}
}
for(int k = 0;k < n;k++){
	if(b[k] == p + 1) c[p] += 1;
}
}
for(int i = 0;i < n;i++){
cout<<c[i]<<" ";
}
return 0;
}
