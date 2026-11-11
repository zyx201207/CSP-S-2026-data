#include<bits/stdc++.h>
using namespace std;
int n;
long long c,t=0,sum=0;
char a,b[10000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   	cin>>n;
   	for(int i=0;i<n;i++){
		cin>>c>>a;
		for(long long j=0;j<c;j++){
			b[t]=a;
			t++;
		}
   	}
   	long long len=t;
   	long long i=0;
   	long long j=t-1;
   	if(len%2==0){
   		while(i>!j){
   			if(b[i]!=b[j]) sum++;
   			i++;
   			j--;
		}
   	}
   	else{
   		while(i!=j){
   			if(b[i]!=b[j]) sum++;
   			i++;
   			j--;
		}
   	}
   	cout<<sum;
    return 0;
}
