 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 	int n,m,num=0;
 	cin>>n>>m;
 	int a[500001];
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		num=num+a[i];
	}
	for(int i=n;i>0;i--){
	if(num+m==n*a[n])cout<<n;
	num=num-a[n];
	n=n-1;
}
 	return 0 ;
 }