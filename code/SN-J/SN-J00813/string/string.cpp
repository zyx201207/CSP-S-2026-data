//SN-J00813 西安翱翔中学 唐子璇 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,change=0;
	long long num[200001];
	char word[200001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>word[i];
	}
	if(n%2==0){
		for(int i=0;i<n/2;i++){
			if(word[p-i]!=word[q+i]){
				if(num[p-i]>num[q+i]){
					change+=num[q+i];
					num[q+i+1]-=num[p-i]-num[q+i];
				}else{
					change+=num[p-i];
					num[p-i-1]-=num[q+i]-num[p-i];
				}
			}
		}
	}else{
		int p=(n+1)/2;
		for(int i=1;i<=n/2;i++){
			if(word[p-i]!=word[p+i]){
				if(num[p-i]>num[p+i]){
					change+=num[p+i];
					num[p+i+1]-=num[p-i]-num[p+i];
				}else{
					change+=num[p-i];
					num[p-i-1]-=num[p+i]-num[p-i];
				}
			}
		}
	}
	cout<<change;
	return 0;
}
