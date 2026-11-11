#include<bits/stdc++.h>
using namespace std;
#define f(i,a,b)for(int i = a;i<=b;i++)
const int N = 2e5+10;
long long ar[N];
char num[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	f(i,1,n){
		cin>>ar[i];
		cin>>num[i];
	}
	int i = 1,j = n;
	long long sum = 0;
	while(i<j){
		if(num[i]!=num[j]){
			if(ar[i]>ar[j]){
				
				sum+=ar[j];
				ar[i]-=ar[j];
				j--;
			}else if(ar[i]<ar[j]){
				ar[j]-=ar[i];
				sum+=ar[i];
				i++;
			}else{
				sum+=ar[i];
				j--;
				i++;
			}
		}else{
			if(ar[i]>ar[j]){
				ar[i]-=ar[j];
				j--;
			}else if(ar[i]<ar[j]){
				ar[j]-=ar[i];
				i++;
			}else{
				j--;
				i++;
			}
		}
	}
	cout<<sum;
}
