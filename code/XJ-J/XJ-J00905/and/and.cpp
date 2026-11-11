#include<bits/stdc++.h>
using namespace std;
string two(int n){
	string s="",s1;
	while(n>1){
		s1=(n%2)+'0';
		s+=s1;
	}
	int len=s.size();
	for(int i=0;i<len;i++) swap(s[i],s[len-i]);
	return s;
}
string andd(string s1,string s2){
	
}
int two_f(string s){
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int arr[n],arr1[n*n],arr1i=0;
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			arr1[arr1i]=two_f(andd(two(arr[i]),two(arr[j])));
			arr1i++;
		}
	}
	sort(arr1,arr1+arr1i);
	cout<<arr1[arr1i];
	return 0;
}