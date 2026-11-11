#include<bits/stdc++.h>
using namespace std;
int number,node=0,sum,ans=0;
char ch,str[2000000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>number;
	while(number){
		cin>>sum>>ch;
		for(int i=1;i<=sum;i++){
			str[++node]=ch;
		}
		number--;
	}
	int left=1,right=node;
	while(left<right){
		if(str[left]!=str[right]) ans++;
		left++;
		right--;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
