#include<bits/stdc++.h>
using namespace std;
int const A=1e5+1;
int n;
unsigned long long a,sum=0;
char c;
struct node{
	unsigned long long num;char c;
}arr[A];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%u",&a);
		cin>>c;
		arr[i].num=a;
		arr[i].c=c;
	}
	int i=1,j=n;
	while(i<j){
		if(arr[i].c!=arr[j].c){
			if(arr[i].num>arr[j].num){
				sum+=arr[j].num;
				arr[i].num=(arr[i].num-arr[j].num);
				j--;
				continue;
			}else if(arr[i].num<arr[j].num){
				sum+=arr[i].num;
				arr[j].num=(arr[j].num-arr[i].num);
				i++;
				continue;
			}else{
				sum+=arr[i].num;
				i++;j--;
				continue;
			}
			continue;
		}else{
			if(arr[i].num>arr[j].num){
				arr[i].num=(arr[i].num-arr[j].num);
				j--;
				continue;
			}else if(arr[i].num<arr[j].num){
				arr[j].num=(arr[j].num-arr[i].num);
				i++;
				continue;
			}else{
				i++;j--;
				continue;
			}
			continue;
		}
	}
	printf("%u",sum);
	return 0;
}
